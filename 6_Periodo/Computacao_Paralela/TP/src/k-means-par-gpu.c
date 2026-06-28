/**
 *  @file k-means-par-gpu.c
 *  @brief K-Means Clustering - Versão Paralela com OpenMP para GPU
 *  
 *  Modificações realizadas para paralelização:
 *  
 *  OPENMP GPU
 *      - Offloading de dados usando target data.
 *      - Execução dos kernels com teams distribute parallel for.
 *      - Uso de operações atômicas para atualização dos clusters.
 *      - Reclassificação dos pontos diretamente na GPU.
 *  
 *  Compilação (Linux/WSL2):
 *      $ gcc -O2 -fopenmp -foffload=nvptx-none k-means-par-gpu.c -o k-means-par-gpu -lm
 *      $ gcc -O2 -fopenmp -foffload=nvptx-none -fcf-protection=none -fno-stack-protector k-means-par-gpu.c -o k-means-par-gpu -lm
 *  
 *  Execução (Linux/WSL2):
 *      $ time ./k-means-par-gpu [num_threads]
 *  
 *  Tempos de execução (Linux/WSL2):
 *      Sequencial         :  3.45s user 3.68s system 99% cpu 7.156 total
 *      OpenMP GPU offload :  1.93s user 4.45s system 95% cpu 6.697 total
 */

#define _USE_MATH_DEFINES /* required for MS Visual C */
#include <float.h>        /* DBL_MAX, DBL_MIN */
#include <math.h>         /* PI, sin, cos */
#include <stdio.h>        /* printf */
#include <stdlib.h>       /* rand */
#include <string.h>       /* memset */
#include <time.h>         /* time */
#include <omp.h>

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
    double x;  /**< abscissa of 2D data point */
    double y;  /**< ordinate of 2D data point */
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
    double x;     /**< abscissa centroid of this cluster */
    double y;     /**< ordinate of centroid of this cluster */
    size_t count; /**< count of observations present in this cluster */
} cluster;

/*!
 * Returns the index of centroid nearest to
 * given observation
 *
 * @param o  observation
 * @param clusters  array of cluster having centroids coordinates
 * @param k  size of clusters array
 *
 * @returns the index of nearest centroid for given observation
 */
int calculateNearst(observation* o, cluster clusters[], int k)
{
    double minD = DBL_MAX;
    double dist = 0;
    int index = -1;
    int i = 0;
    for (; i < k; i++)
    {
        /* Calculate Squared Distance*/
        dist = (clusters[i].x - o->x) * (clusters[i].x - o->x) +
               (clusters[i].y - o->y) * (clusters[i].y - o->y);
        if (dist < minD)
        {
            minD = dist;
            index = i;
        }
    }
    return index;
}

/*!
 * Calculate centoid and assign it to the cluster variable
 *
 * @param observations  an array of observations whose centroid is calculated
 * @param size  size of the observations array
 * @param centroid  a reference to cluster object to store information of
 * centroid
 */
void calculateCentroid(observation observations[], size_t size,
                       cluster* centroid)
{
    size_t i = 0;
    centroid->x = 0;
    centroid->y = 0;
    centroid->count = size;
    for (; i < size; i++)
    {
        centroid->x += observations[i].x;
        centroid->y += observations[i].y;
        observations[i].group = 0;
    }
    centroid->x /= centroid->count;
    centroid->y /= centroid->count;
}

/*!
 *    --K Means Algorithm--
 * 1. Assign each observation to one of k groups
 *    creating a random initial clustering
 * 2. Find the centroid of observations for each
 *    cluster to form new centroids
 * 3. Find the centroid which is nearest for each
 *    observation among the calculated centroids
 * 4. Assign the observation to its nearest centroid
 *    to create a new clustering.
 * 5. Repeat step 2,3,4 until there is no change
 *    the current clustering and is same as last
 *    clustering.
 *
 * @param observations  an array of observations to cluster
 * @param size  size of observations array
 * @param k  no of clusters to be made
 *
 * @returns pointer to cluster object
 */
cluster* kMeans(observation observations[], size_t size, int k, int num_threads)
{
    cluster* clusters = NULL;
    omp_set_num_threads(num_threads);
    if (k <= 1)
    {
        /*
        If we have to cluster them only in one group
        then calculate centroid of observations and
        that will be a ingle cluster
        */
        clusters = (cluster*)malloc(sizeof(cluster));
        memset(clusters, 0, sizeof(cluster));
        calculateCentroid(observations, size, clusters);
    }
    else if (k < size)
    {
        clusters = malloc(sizeof(cluster) * k);
        memset(clusters, 0, k * sizeof(cluster));
        /* STEP 1 */
        for (size_t j = 0; j < size; j++)
        {
            observations[j].group = rand() % k;
        }
        size_t changed = 0;
        size_t minAcceptedError =
            size /
            10000;  // Do until 99.99 percent points are in correct cluster
        int t = 0;
        do
        {
            /* Initialize clusters */
            for (int i = 0; i < k; i++)
            {
                clusters[i].x = 0;
                clusters[i].y = 0;
                clusters[i].count = 0;
            }

            /* STEP 2*/
            #pragma omp target teams distribute parallel for \
                map(to: observations[0:size]) \
                map(tofrom: clusters[0:k])
            for (size_t j = 0; j < size; j++)
            {
                t = observations[j].group;

                #pragma omp atomic
                clusters[t].x += observations[j].x;

                #pragma omp atomic
                clusters[t].y += observations[j].y;

                #pragma omp atomic
                clusters[t].count++;
            }

            #pragma omp target teams distribute parallel for \
                map(tofrom: clusters[0:k])
            for (int i = 0; i < k; i++)
            {
                clusters[i].x /= clusters[i].count;
                clusters[i].y /= clusters[i].count;
            }

            /* STEP 3 and 4 */
            changed = 0;  // this variable stores change in clustering

            #pragma omp target teams distribute parallel for \
                map(tofrom: observations[0:size]) \
                map(to: clusters[0:k]) \
                reduction(+:changed)
            for (size_t j = 0; j < size; j++)
            {
                // Calcula o mais proximo
                double minD = DBL_MAX;
                int nearest = -1;

                for (int i = 0; i < k; i++)
                {
                    double dist =
                        (clusters[i].x - observations[j].x) *
                        (clusters[i].x - observations[j].x) +
                        (clusters[i].y - observations[j].y) *
                        (clusters[i].y - observations[j].y);

                    if (dist < minD)
                    {
                        minD = dist;
                        nearest = i;
                    }
                }

                if (nearest != observations[j].group)
                {
                    changed++;
                    observations[j].group = nearest;
                }

                if (t != observations[j].group)
                {
                    changed++;
                    observations[j].group = t;
                }
            }
        } while (changed > minAcceptedError);  // Keep on grouping until we have
                                               // got almost best clustering
    }
    else
    {
        /* If no of clusters is more than observations
           each observation can be its own cluster
        */
        clusters = (cluster*)malloc(sizeof(cluster) * k);
        memset(clusters, 0, k * sizeof(cluster));
        for (int j = 0; j < size; j++)
        {
            clusters[j].x = observations[j].x;
            clusters[j].y = observations[j].y;
            clusters[j].count = 1;
            observations[j].group = j;
        }
    }
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
    double min_x = DBL_MAX, max_x = DBL_MIN, min_y = DBL_MAX, max_y = DBL_MIN;
    double scale = 0, cx = 0, cy = 0;
    double* colors = (double*)malloc(sizeof(double) * (k * 3));
    int i;
    size_t j;
    double kd = k * 1.0;
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
static void test(int num_threads)
{
    size_t size = 100000L;
    observation* observations =
        (observation*)malloc(sizeof(observation) * size);
    double maxRadius = 20.00;
    double radius = 0;
    double ang = 0;
    size_t i = 0;
    for (; i < size; i++)
    {
        radius = maxRadius * ((double)rand() / RAND_MAX);
        ang = 2 * M_PI * ((double)rand() / RAND_MAX);
        observations[i].x = radius * cos(ang);
        observations[i].y = radius * sin(ang);
    }
    int k = 5;  // No of clusters'

    fprintf(stderr, "Dataset: %zu pontos, %d clusters\n", size, k);
    fprintf(stderr, "Threads: %d\n", num_threads);
    
    double t0 = omp_get_wtime();
    cluster* clusters = kMeans(observations, size, k, num_threads);
    double t1 = omp_get_wtime();

    printEPS(observations, size, clusters, k);

    fprintf(stderr, "Tempo de execução: %.4f s\n", t1 - t0);

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
void test2(int num_threads)
{
    size_t size = 1000000L;
    observation* observations =
        (observation*)malloc(sizeof(observation) * size);
    double maxRadius = 20.00;
    double radius = 0;
    double ang = 0;
    size_t i = 0;
    for (; i < size; i++)
    {
        radius = maxRadius * ((double)rand() / RAND_MAX);
        ang = 2 * M_PI * ((double)rand() / RAND_MAX);
        observations[i].x = radius * cos(ang);
        observations[i].y = radius * sin(ang);
    }
    int k = 11;  // No of clusters

    fprintf(stderr, "Dataset: %zu pontos, %d clusters\n", size, k);
    fprintf(stderr, "Threads: %d\n", num_threads);
    
    double t0 = omp_get_wtime();
    cluster* clusters = kMeans(observations, size, k, num_threads);
    double t1 = omp_get_wtime();

    printEPS(observations, size, clusters, k);

    fprintf(stderr, "Tempo de execução: %.4f s\n", t1 - t0);

    // Free the accquired memory
    free(observations);
    free(clusters);
}

/*!
 * This function calls the test
 * function
 */
int main(int argc, char *argv[])
{
    int num_threads = (argc > 1) ? atoi(argv[1]) : omp_get_max_threads();
    if (num_threads < 1)
        num_threads = 1;
    
    srand(time(NULL));
    // test(num_threads);
    test2(num_threads);
    
    return 0;
}