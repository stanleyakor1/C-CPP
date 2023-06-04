#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Dlist
{
    int item;
    int key;
    struct Dlist *next;
    struct Dlist *prev;
}Dlist; 

// setting up global variables!
Dlist *head = NULL;
Dlist *tail = NULL;

bool isEmpty()
{
    return (head == NULL);
}

void Forwardprint()
{
    Dlist *ptr = head;
    if(!head)
        return;

    while(ptr)
    {
        printf("%d, %d",ptr->key,ptr->item);
        ptr = ptr->next;
        printf(" ");
    }
    printf("\n");
}
void Backwardprint()
{
    Dlist *ptr = tail;

    if(!ptr)
        return ;

    while(ptr)
    {
       printf("%d, %d",ptr->key,ptr->item); 
       ptr = ptr->prev;
       printf(" ");
    }
    printf("\n");
}

//**head (the global head)
 void addfirst(int Item, int Key)
{
    Dlist *ptr = (Dlist *)malloc(sizeof(Dlist));

    if(!ptr)
    {
        printf("Failed memory allocation!");
        return;
    }

    ptr->item = Item;
    ptr->key = Key;

    //attach to node
    ptr -> next = head;

    if (head)
        (head)->prev = ptr;

    //initially empty doublylinked list
    else
    {
        head = ptr;
        tail = head;
    }
   head = ptr;
}

void addLast(int Item, int Key)
{
    Dlist * ptr = (Dlist *) malloc(sizeof(Dlist));

    if(!ptr)
        return;

    ptr -> item = Item;
    ptr -> key = Key;

    if(tail)
    {
        tail -> next= ptr;
        ptr -> prev = tail;
    }
    
    tail = ptr;
}

void removeLast()
{
     Dlist * ptr = (Dlist *) malloc(sizeof(Dlist));

     if(!tail)
     {
        printf("List is already empty");
        return;
     }

    ptr = tail->prev;
    if(ptr)
     {
        ptr->next = NULL;
         free(tail); //deallocate memory for the removed node
        tail = ptr;
     }

     else
     {
        head = NULL;
        tail = NULL;
    }
   
}

int main(void)
{
    // Code for testing the doubly linked list functionality
    addfirst(100,1);
    addfirst(120,2);
    addfirst(150,3);
    addfirst(155,5);
    addLast(178,9);
    addLast(200,11);
    Forwardprint();
    removeLast();
    removeLast();
    Forwardprint();
    
    return 0;
}