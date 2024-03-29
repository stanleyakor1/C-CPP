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


//add last node
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

// remove last node
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


//check size of the doubly linked list
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

// remove a node at a particular position
// index of pos starts from 0.

void removePos(int pos)
{
   int len = size();
   if(pos>len - 1|| !head)
        return;

   Dlist *current = head;

   if(pos == 0)
   {
    removeFirst();
    return;
   } 
  if(pos == len - 1)
  {
    removeLast();
    return;
  }
   for(int i=0; i<pos;i++)
   {
        if(!current)
            return;

        current = current->next;
   }
    Dlist * prevv = current->prev;
    Dlist * nextt = current->next;

    if (prevv != NULL)
      prevv->next = nextt;

    if (nextt != NULL)
      nextt->prev = prevv;

    if(current == tail)
        tail = prevv;

     free(current);
}


//add node to a position
void AddPos(int Item, int Key, int pos)
{

     if (!head || pos <= 0)
     {
        addfirst(Item, Key);
        return;
     }
     int len = size();
     if (pos >= len)
     {
        addLast(Item, Key);
        return;
     }

     Dlist *ptr = (Dlist *)malloc(sizeof(Dlist));
     ptr->key = Key;
     ptr->item = Item;

     Dlist *current = head;

     for (int i = 0; i < pos - 1; i++)
     {
        if(!current)
            return;

        current = current->next;
   }

    Dlist * prevv = current;
    Dlist * nextt = current->next;

    prevv->next = ptr;
    ptr->prev = prevv;

    if (ptr != NULL)
      ptr->next = nextt;

    if (nextt != NULL)
      nextt->prev = ptr;
     

}

//checks if an item exists in the list
bool search(int Key)
{
    if(!head)
        return false;

    Dlist * current = head;

    while(current)
    {
        if(current->key == Key)
            return true;

        current = current->next;
    }

    return false;
}


//returns the position of the item in the list

int indexx(int Key)
{
    if(!head)
        return -1;

    Dlist * current = head;

    int pos = 0;

    while(current)
    {
        if(current->key == Key)
            return pos;
        pos++;

        current = current->next;
    }

    return -1;
}

// main code!
int main(void)
{
    // Code for testing the doubly linked list functionality
    addfirst(100,1);
    addfirst(120,2);
    addfirst(150,3);
    addfirst(155,4);
    addLast(178,5);
    addLast(200,6);
    //Forwardprint();
    //removeLast();
    //removeLast();
    Forwardprint();
    //removePos(2);
    //removeFirst();
    //removeFirst();
    AddPos(123,99,3);
    Forwardprint();
    int len = size();
    printf("size = %d\n", len);



    bool find = search(4);
    printf("search result = %d\n", find);

    int pos = indexx(6);
    printf("The position of the key = %d\n", pos);

    return 0;
}