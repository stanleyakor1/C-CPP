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

//delete the first item on the list
void removeFirst()
{

   if(!head)
        return;

    Dlist *ptr = head->next;
    free(head);
    if(ptr)
    {
        ptr->prev = NULL;
        head = ptr;
    }
    else
        head = NULL;
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
        free(tail); //deallocate memory for the removed node
        head = NULL;
        tail = NULL;
    }
   
}

int  size()
{
    if(!head)
        return 0;
    
    int count = 0;
    Dlist * current = head;

    while(current)
    {
        current= current->next;
        count++;
    }
    return count;

}


void removePos( int pos)
{
   //Dlist * ptr = (Dlist *) malloc(sizeof(Dlist));
   int len = size();
   if(pos>len|| !head)
        return;

   Dlist *current = head; 

   for(int i=0; i<pos;i++)
        current = current->next;

    Dlist * prevv = current->prev;
    Dlist * nextt = current->next;
    free(current);

    prevv->next = nextt;
    nextt->prev = prevv;

    head = prevv;
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
    //removeLast();
    //removeLast();
    Forwardprint();
    removePos(2);
    //removeFirst();
    //removeFirst();
    Forwardprint();
    int len = size();
    printf("size = %d\n", len);
    return 0;
}