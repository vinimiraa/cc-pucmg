/**
 * @file k-means-cuda.cu
 * @brief K-Means Clustering - Versão GPU com CUDA
 *
 * Compilação (Linux/WSL2):
 *   $ nvcc -O2 k-means-cuda.cu -o k-means-cuda
 *
 * Execução (Linux/WSL2):
 *   $ time ./k-means-cuda
 * 
 *  Tempos de execução (Linux/WSL2):
 *      Sequencial         :  3.45s user 3.68s system 99% cpu 7.156 total
 *      OpenMP GPU offload :  1.44s user 4.12s system 96% cpu 5.773 total
 */

#define _USE_MATH_DEFINES /* required for MS Visual C */
#include <float.h>        /* DBL_MAX, DBL_MIN */
#include <math.h>         /* PI, sin, cos */
#include <stdio.h>        /* printf */
#include <stdlib.h>       /* rand */
#include <string.h>       /* memset */
#include <time.h>         /* time */
#include <cuda_runtime.h>

/*!
 * @addtogroup machine_learning Machine Learning Algorithms
 * @{
 * @addtogroup k_means K-Means Clustering Algorithm
 * @{
 */

/*! @struct observation
 *  a class to store points in 2d plane
 *  the name observation is used to denote
 *  a random point in plane
 */
typedef struct observation
{
    float x;  /**< abscissa of 2D data point */
    float y;  /**< ordinate of 2D data point */
    int group; /**< the group no in which this observation would go */
} observation;

/*! @struct cluster
 *  this class stores the coordinates
 *  of centroid of all the points
 *  in that cluster it also
 *  stores the count of observations
 *  belonging to this cluster
 */
typedef struct cluster
{
    float x;     /**< abscissa centroid of this cluster */
    float y;     /**< ordinate of centroid of this cluster */
    size_t count; /**< count of observations present in this cluster */
} cluster;

__global__ void accumulateClusters(observation *obs, cluster *clusters, size_t size)
{
    size_t j = blockIdx.x * blockDim.x + threadIdx.x;

    if (j < size)
    {
        int t = obs[j].group;

        atomicAdd(&clusters[t].x, obs[j].x);
        atomicAdd(&clusters[t].y, obs[j].y);
        atomicAdd((unsigned long long *)&clusters[t].count, 1ULL);
    }
}

__global__ void updateCentroids(cluster *clusters, int k)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < k && clusters[i].count > 0)
    {
        clusters[i].x /= clusters[i].count;
        clusters[i].y /= clusters[i].count;
    }
}

__device__ int calculateNearest(observation *o, cluster *clusters, int k)
{
    float minD = DBL_MAX;
    int index = -1;

    for (int i = 0; i < k; i++)
    {
        float dist =
            (clusters[i].x - o->x) * (clusters[i].x - o->x) +
            (clusters[i].y - o->y) * (clusters[i].y - o->y);

        if (dist < minD)
        {
            minD = dist;
            index = i;
        }
    }

    return index;
}

__global__ void reassignClusters(observation *obs, cluster *clusters, size_t size, int k, unsigned int *changed)
{
    size_t j = blockIdx.x * blockDim.x + threadIdx.x;

    if (j < size)
    {
        int nearest =
            calculateNearest(&obs[j], clusters, k);

        if (nearest != obs[j].group)
        {
            obs[j].group = nearest;
            atomicAdd(changed, 1);
        }
    }
}

__global__ void resetClusters(cluster *clusters, int k)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < k)
    {
        clusters[i].x = 0.0;
        clusters[i].y = 0.0;
        clusters[i].count = 0;
    }
}

cluster *kMeans(observation observations[], size_t size, int k)
{
    cluster *clusters = (cluster *)malloc(sizeof(cluster) * k);

    observation *d_obs;
    cluster *d_clusters;
    unsigned int *d_changed;

    cudaMalloc(&d_obs, size * sizeof(observation));
    cudaMalloc(&d_clusters, k * sizeof(cluster));
    cudaMalloc(&d_changed, sizeof(unsigned int));

    cudaMemcpy(
        d_obs,
        observations,
        size * sizeof(observation),
        cudaMemcpyHostToDevice);

    for (size_t j = 0; j < size; j++)
        observations[j].group = rand() % k;

    cudaMemcpy(
        d_obs,
        observations,
        size * sizeof(observation),
        cudaMemcpyHostToDevice);

    size_t minAcceptedError = size / 10000;

    unsigned int changed;

    int blockSize = 256;

    do
    {
        changed = 0;

        cudaMemcpy(
            d_changed,
            &changed,
            sizeof(unsigned int),
            cudaMemcpyHostToDevice);

        resetClusters<<<(k + blockSize - 1) / blockSize,
                        blockSize>>>(d_clusters, k);

        accumulateClusters<<<(size + blockSize - 1) / blockSize,
                             blockSize>>>(d_obs, d_clusters, size);

        updateCentroids<<<(k + blockSize - 1) / blockSize,
                          blockSize>>>(d_clusters, k);

        reassignClusters<<<(size + blockSize - 1) / blockSize,
                           blockSize>>>(d_obs, d_clusters, size, k, d_changed);

        cudaMemcpy(&changed, d_changed, sizeof(unsigned int), cudaMemcpyDeviceToHost);

    } while (changed > minAcceptedError);

    cudaMemcpy(observations, d_obs, size * sizeof(observation), cudaMemcpyDeviceToHost);

    cudaMemcpy(clusters, d_clusters, k * sizeof(cluster), cudaMemcpyDeviceToHost);

    cudaFree(d_obs);
    cudaFree(d_clusters);
    cudaFree(d_changed);

    return clusters;
}

/**
 * @}
 * @}
 */

/*!
 * A function to print observations and clusters
 * The code is taken from
 * http://rosettacode.org/wiki/K-means%2B%2B_clustering.
 * Even the K Means code is also inspired from it
 *
 * @note To print in a file use pipeline operator
 * ```sh
 * ./k_means_clustering > image.eps
 * ```
 *
 * @param observations  observations array
 * @param len  size of observation array
 * @param cent  clusters centroid's array
 * @param k  size of cent array
 */
void printEPS(observation pts[], size_t len, cluster cent[], int k)
{
    int W = 400, H = 400;
    float min_x = DBL_MAX, max_x = DBL_MIN, min_y = DBL_MAX, max_y = DBL_MIN;
    float scale = 0, cx = 0, cy = 0;
    float *colors = (float *)malloc(sizeof(float) * (k * 3));
    int i;
    size_t j;
    float kd = k * 1.0;
    for (i = 0; i < k; i++)
    {
        *(colors + 3 * i) = (3 * (i + 1) % k) / kd;
        *(colors + 3 * i + 1) = (7 * i % k) / kd;
        *(colors + 3 * i + 2) = (9 * i % k) / kd;
    }

    for (j = 0; j < len; j++)
    {
        if (max_x < pts[j].x)
        {
            max_x = pts[j].x;
        }
        if (min_x > pts[j].x)
        {
            min_x = pts[j].x;
        }
        if (max_y < pts[j].y)
        {
            max_y = pts[j].y;
        }
        if (min_y > pts[j].y)
        {
            min_y = pts[j].y;
        }
    }
    scale = W / (max_x - min_x);
    if (scale > (H / (max_y - min_y)))
    {
        scale = H / (max_y - min_y);
    };
    cx = (max_x + min_x) / 2;
    cy = (max_y + min_y) / 2;

    printf("%%!PS-Adobe-3.0 EPSF-3.0\n%%%%BoundingBox: -5 -5 %d %d\n", W + 10,
           H + 10);
    printf(
        "/l {rlineto} def /m {rmoveto} def\n"
        "/c { .25 sub exch .25 sub exch .5 0 360 arc fill } def\n"
        "/s { moveto -2 0 m 2 2 l 2 -2 l -2 -2 l closepath "
        "	gsave 1 setgray fill grestore gsave 3 setlinewidth"
        " 1 setgray stroke grestore 0 setgray stroke }def\n");
    for (int i = 0; i < k; i++)
    {
        printf("%g %g %g setrgbcolor\n", *(colors + 3 * i),
               *(colors + 3 * i + 1), *(colors + 3 * i + 2));
        for (j = 0; j < len; j++)
        {
            if (pts[j].group != i)
            {
                continue;
            }
            printf("%.3f %.3f c\n", (pts[j].x - cx) * scale + W / 2,
                   (pts[j].y - cy) * scale + H / 2);
        }
        printf("\n0 setgray %g %g s\n", (cent[i].x - cx) * scale + W / 2,
               (cent[i].y - cy) * scale + H / 2);
    }
    printf("\n%%%%EOF");

    // free accquired memory
    free(colors);
}

/*!
 * A function to test the kMeans function
 * Generates 100000 points in a circle of
 * radius 20.0 with center at (0,0)
 * and cluster them into 5 clusters
 *
 * <img alt="Output for 100000 points divided in 5 clusters" src=
 * "https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/machine_learning/k_means_clustering/kMeansTest1.png"
 * width="400px" heiggt="400px">
 * @returns None
 */
static void test()
{
    size_t size = 100000L;
    observation *observations =
        (observation *)malloc(sizeof(observation) * size);
    float maxRadius = 20.00;
    float radius = 0;
    float ang = 0;
    size_t i = 0;
    for (; i < size; i++)
    {
        radius = maxRadius * ((float)rand() / RAND_MAX);
        ang = 2 * M_PI * ((float)rand() / RAND_MAX);
        observations[i].x = radius * cos(ang);
        observations[i].y = radius * sin(ang);
    }
    int k = 5; // No of clusters
    cluster *clusters = kMeans(observations, size, k);
    printEPS(observations, size, clusters, k);
    // Free the accquired memory
    free(observations);
    free(clusters);
}

/*!
 * A function to test the kMeans function
 * Generates 1000000 points in a circle of
 * radius 20.0 with center at (0,0)
 * and cluster them into 11 clusters
 *
 * <img alt="Output for 1000000 points divided in 11 clusters" src=
 * "https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/machine_learning/k_means_clustering/kMeansTest2.png"
 * width="400px" heiggt="400px">
 * @returns None
 */
void test2()
{
    size_t size = 1000000L;
    observation *observations =
        (observation *)malloc(sizeof(observation) * size);
    float maxRadius = 20.00;
    float radius = 0;
    float ang = 0;
    size_t i = 0;
    for (; i < size; i++)
    {
        radius = maxRadius * ((float)rand() / RAND_MAX);
        ang = 2 * M_PI * ((float)rand() / RAND_MAX);
        observations[i].x = radius * cos(ang);
        observations[i].y = radius * sin(ang);
    }
    int k = 11; // No of clusters
    cluster *clusters = kMeans(observations, size, k);
    printEPS(observations, size, clusters, k);
    // Free the accquired memory
    free(observations);
    free(clusters);
}

/*!
 * This function calls the test
 * function
 */
int main()
{
    srand(time(NULL));
    // test();
    test2();
    return 0;
}