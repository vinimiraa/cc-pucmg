#include "list.h"

// ----------------------------
// Error Handling
// ----------------------------

/**
 *  @brief Error codes for list operations.
 *  These codes are used to identify specific errors that may occur during list operations.
 */
enum _errorCodes
{
    ERROR_NODE_MEMORY_ALLOCATION = 1,
    ERROR_LIST_MEMORY_ALLOCATION,
    ERROR_FREE_LIST,
    ERROR_INVALID_POSITION,
    ERROR_NULL_LIST,
    ERROR_NULL_NODE,
    ERROR_NULL_DATA,
    ERROR_EMPTY_LIST
};

/**
 *  @brief Prints error messages based on the error code.
 *  @param errorCode The error code to be printed.
 */
void _printErrorList(int errorCode)
{
    switch(errorCode)
    {
        case ERROR_NODE_MEMORY_ALLOCATION:
            fprintf(stderr, "Error: Memory allocation failed for new node.\n");
            break;
        case ERROR_LIST_MEMORY_ALLOCATION:
            fprintf(stderr, "Error: Memory allocation failed for new list.\n");
            break;
        case ERROR_FREE_LIST:
            fprintf(stderr, "Error: Attempt to free a NULL list.\n");
            break;
        case ERROR_INVALID_POSITION:
            fprintf(stderr, "Error: Invalid position for operation.\n");
            break;
        case ERROR_NULL_LIST:
            fprintf(stderr, "Error: Attempt to operate on a NULL list.\n");
            break;
        case ERROR_NULL_NODE:
            fprintf(stderr, "Error: Attempt to operate on a NULL node.\n");
            break;
        case ERROR_NULL_DATA:
            fprintf(stderr, "Error: Attempt to operate on NULL data.\n");
            break;
        case ERROR_EMPTY_LIST:
            fprintf(stderr, "Error: Attempt to operate on an empty list.\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown error code %d.\n", errorCode);
    }
}

// ----------------------------
// List Implementation
// ----------------------------

/**
 *  @brief Creates a new node with the given data.
 *  @param data The data to be stored in the new node.
 */
Node* _nodeCreate(void* data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL)
    {
        _printErrorList(ERROR_NODE_MEMORY_ALLOCATION);
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

/**
 *  @brief Creates a new list and initializes its head, tail, and size.
 *  @return A pointer to the newly created list.
 */
List* listCreate(void)
{
    List* newList = (List*) malloc(sizeof(List));
    if(newList == NULL)
    {
        _printErrorList(ERROR_LIST_MEMORY_ALLOCATION);
    }
    else
    {
        newList->head = newList->tail = _nodeCreate(NULL);
        newList->size = 0;
    }
    return newList;
}

/**
 *  @brief Frees the memory allocated for the list and its nodes.
 *  @param list The list to be freed.
 */
void listFree(List* list)
{
    if(list == NULL)
    {
        _printErrorList(ERROR_FREE_LIST);
    }
    else
    {
        Node* current = list->head;
        Node* nextNode = NULL;
        while(current != NULL) 
        {
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
        free(list);
        list = NULL;
    }
}

/**
 *  @brief Inserts a new node at the beginning of the list.
 *  @param data The data to be stored in the new node.
 *  @param list The list where the node will be inserted.
 */
void listInsertAtBeginning(void* data, List* list)
{
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else
    {
        Node* newNode = _nodeCreate(data);
        if(newNode != NULL)
        {
            newNode->next = list->head->next;
            list->head->next = newNode;
            if(list->head == list->tail) 
            {                    
                list->tail = newNode;
            }
            newNode = NULL;
            list->size++;
        }
    }
}

/**
 *  @brief Inserts a new node at the end of the list.
 *  @param data The data to be stored in the new node.
 *  @param list The list where the node will be inserted.
 */
void listInsertAtEnd(void* data, List* list)
{
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else
    {
        Node* newNode = _nodeCreate(data);
        if(newNode != NULL)
        {
            list->tail->next = newNode;
            list->tail = list->tail->next;
            list->size++;
        }
    }
}

/**
 *  @brief Inserts a new node at the specified index in the list.
 *  @param index The index where the new node will be inserted.
 *  @param data The data to be stored in the new node.
 *  @param list The list where the node will be inserted.
 */
void listInsertAt(int index, void* data, List* list)
{
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else if(index < 0 || list->size < index) 
    {
        _printErrorList(ERROR_INVALID_POSITION);
    } 
    else if(index == 0) 
    {
        listInsertAtBeginning(data, list);
    } 
    else if(index == list->size) 
    {
        listInsertAtEnd(data, list);
    } 
    else 
    {
        Node* current = list->head;
        for(int j = 0; j < index; j = j + 1, current = current->next);   
        Node* newNode = _nodeCreate(data);
        if(newNode != NULL)
        {
            newNode->next = current->next;
            current->next = newNode;
            newNode = current = NULL;
            list->size++;
        }
    }
}

/**
 *  @brief Removes the node at the beginning of the list.
 *  @param list The list from which the node will be removed.
 *  @return The data stored in the removed node.
 */
void* listRemoveAtBeginning(List* list)
{
    void* data = NULL;
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else if(list->head == list->tail) 
    {
        _printErrorList(ERROR_EMPTY_LIST);
    } 
    else 
    {
        Node* temp = list->head->next;
        data = temp->data;
        list->head->next = temp->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
        list->size--;
    }
    return data;
}

/**
 *  @brief Removes the node at the end of the list.
 *  @param list The list from which the node will be removed.
 *  @return The data stored in the removed node.
 *  @note This function assumes that the list has at least two nodes.
 */
void* listRemoveAtEnd(List* list)
{
    void* data = NULL;
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else if(list->head == list->tail) 
    {
        _printErrorList(ERROR_EMPTY_LIST);
    } 
    else 
    {
        Node* current = NULL;
        for(current = list->head; current->next != list->tail; current = current->next);
        data = list->tail->data;
        list->tail = current;
        free(list->tail->next);
        current = list->tail->next = NULL;
        list->size--;
    }
    return data;
}

/**
 *  @brief Removes the node at the specified index in the list.
 *  @param index The index of the node to be removed.
 *  @param list The list from which the node will be removed.
 *  @return The data stored in the removed node.
 */
void* listRemoveAt(int index, List* list)
{
    void* data = NULL;
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else if(list->head == list->tail) 
    {
        _printErrorList(ERROR_EMPTY_LIST);
    } 
    else if(index < 0 || index >= list->size) 
    {
        _printErrorList(ERROR_INVALID_POSITION);
    } 
    else if(index == 0) 
    {
        data = listRemoveAtBeginning(list);
    } 
    else if(index == list->size - 1) 
    {
        data = listRemoveAtEnd(list);
    } 
    else 
    {
        Node* current = list->head;
        for(int j = 0; j < index; j = j + 1, current = current->next);
        Node* temp = current->next;
        data = temp->data;
        current->next = temp->next;
        temp->next = NULL;
        free(temp);
        current = temp = NULL;
        list->size--;
    }
    return data;
}

/**
 *  @brief Prints the elements of the list using the provided print function.
 *  @param list The list to be printed.
 *  @param printFunc The function used to print each element of the list.
 */
void listPrint(List* list, void (*printFunc)(void* data))
{
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else
    {
        printf("[ ");
        Node* current = list->head->next;
        while(current != NULL) 
        {
            printFunc(current->data);
            current = current->next;
        }
        printf("]\n");
    }
}

/**
 *  @brief Searches for a specific element in the list using the provided comparison function.
 *  @param list The list to be searched.
 *  @param data The data to be searched for.
 *  @param compareFunc The function used to compare elements in the list.
 *  @return The index of the found element, or -1 if not found.
 */
int listSearch(List* list, void* data, int (*compareFunc)(void* a, void* b))
{
    int found = -1;
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else
    {
        Node* current = list->head->next;
        int index = 0;
        while(current != NULL) 
        {
            if(compareFunc(data, current->data) == 0) 
            {
                found = index;
            }
            current = current->next;
            index++;
        }
    }
    return found;
}

/**
 *  @brief Returns the size of the list.
 *  @param list The list whose size is to be returned.
 *  @return The size of the list.
 */
int listGetSize(List* list)
{
    int size = -1;
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else
    {
        size = list->size;
    }
    return size;
}

/**
 *  @brief Returns the element at the specified index in the list.
 *  @param index The index of the element to be returned.
 *  @param list The list from which the element will be returned.
 *  @return The data stored in the node at the specified index.
 */
void* listGetAt(int index, List* list)
{
    void* data = NULL;
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else if(index < 0 || index >= list->size) 
    {
        _printErrorList(ERROR_INVALID_POSITION);
    } 
    else 
    {
        Node* current = list->head->next;
        for(int j = 0; j < index; j = j + 1, current = current->next);
        data = current->data;
    }
    return data;
} // end getElementAt ( )

/**
 *  @brief Checks if the list is empty.
 *  @param list The list to be checked.
 *  @return true if the list is empty, false otherwise.
 */
bool listIsEmpty(List* list)
{
    bool isEmpty = false;
    if(list == NULL)
    {
        _printErrorList(ERROR_NULL_LIST);
    }
    else
    {
        isEmpty = (list->size == 0) ? true : false;
    }
    return isEmpty;
}

