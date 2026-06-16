#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  @brief Node structure for the linked list.
 *  @struct s_Node
 *  @param data Pointer to the data stored in the node.
 *  @param next Pointer to the next node in the list.
 *  @note The data pointer can point to any type of data, allowing for a generic linked list.
 */
typedef struct s_Node
{
    void* data;
    struct s_Node* next;
} Node;

/**
 *  @brief List structure for the linked list.
 *  @struct s_List
 *  @param head Pointer to the first node in the list.
 *  @param tail Pointer to the last node in the list.
 *  @param size The number of nodes in the list.
 *  @note The head is a dummy node, and the tail is the last node in the list.
 *        The size is updated whenever nodes are added or removed from the list.
 */
typedef struct s_List
{
    Node* head;
    Node* tail;
    int size;
} List;

List* listCreate(void);
void  listFree(List* list);
void  listInsertAtBeginning(void* data, List* list);
void  listInsertAtEnd(void* data, List* list);
void  listInsertAt(int index, void* data, List* list);
void* listRemoveAtBeginning(List* list);
void* listRemoveAtEnd(List* list);
void* listRemoveAt(int index, List* list);
void  listPrint(List* list, void (*printFunc)(void* data));
int   listSearch(List* list, void* data, int (*compareFunc)(void* a, void* b));
void* listGetAt(int index, List* list);
int   listGetSize(List* list);
bool  listIsEmpty(List* list);

#endif // __LIST_H__