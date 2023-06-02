#include <stdio.h>
#include <stdlib.h>

// struct may refer to a pointer of its own type.
struct List
{
    int item;
    struct List *next;
};

struct List *insert_Atbegining(struct List *node, int item)
{
   struct List *newnode = (struct List *)malloc(sizeof(struct List));
    if(newnode == NULL) //Failed memory allocation
    {
        return NULL;
    }
    newnode->item  = item;
    newnode->next = node;

    return newnode;
}



struct List *insert_Atend(struct List *node, int item)
{
    struct List *newnode = (struct List *)malloc(sizeof(struct List));
    if(newnode == NULL)
    {
        return NULL;
    }
    newnode->item  = item;
    newnode->next = NULL;

    // if list is empty

     if (!node)
        return NULL;

    // if list is not empty.
    struct List *current = node;
   
    while(current->next)
    {
       current = current->next;
    }

    current->next = newnode;

    return node;
}
void printList(struct List *node) 
{
    while (node != NULL) {
        printf("%d ", node->item);
        node = node->next;
    }
    printf("\n");
}

//free a singly linked list
void delete_slist(struct List *node)
{
    struct List * current = node;
    struct List * next;
    while (current!=NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
int main(void) {
    struct List *list = NULL;

    list = insert_Atbegining(list, 5);
    list = insert_Atbegining(list, 3);
    list = insert_Atend(list, 10);

    printList(list);
    //delete_slist(list);
   

    return 0;
}