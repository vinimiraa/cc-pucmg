#include "list.h"

typedef struct s_Point
{
    int x, y;
} Point;

void printPoint(void* data)
{
    Point* point = (Point*)data;
    printf("(%d, %d) ", point->x, point->y);
}

int comparePoint(void* a, void* b)
{
    int cmp = 0;
    Point* pointA = (Point*)a;
    Point* pointB = (Point*)b;
    if(pointA->x == pointB->x && pointA->y == pointB->y)
        cmp = 0;
    else if(pointA->x < pointB->x || (pointA->x == pointB->x && pointA->y < pointB->y))
        cmp = -1;
    else
        cmp = 1;

    return cmp;
}

int main(void)
{
    List* list = listCreate();

    Point* point;
    for(int i = 0; i < 10; i++)
    {
        point = (Point*)malloc(sizeof(Point));
        point->x = i;
        point->y = i * 2;
        listInsertAtEnd(point, list);
    }

    printf("List after inserting elements at the end:\n");
    listPrint(list, printPoint);
    
    Point searchValue = {2, 4};
    int index = listSearch(list, &searchValue, comparePoint);
    if (index != -1)
    {
        printf("Found (2, 4) at index %d\n", index);
    }
    else
    {
        printf("(2, 4) not found in the list\n");
    }
    
    listFree(list);
    
    return 0;
}
