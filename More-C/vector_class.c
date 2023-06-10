
#include "vector.h"

//a flexible vector class, similar to those in the vector library in c++

// Reference: An Introduction to the C Programming Language and Software Design. Tim Bailey


static const int start_size = 5;
static const float growthRate = 1.6f;

Vector create_vector(int capacity)
{
    Vector v;

    v.size = 0; // initial size of the vector 

    v.data = (ValueType *)malloc(sizeof(ValueType)*capacity);

    v.capacity = (v.data == NULL)? 0: capacity;

    return v;
}

void delete_vector(Vector * v)
{
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}


// add item to the back of the vector
int push_back(Vector *v, ValueType item)
{
    if(v->size == v->capacity)
    {
        int newsiz = (v->capacity == 0)?start_size:(int)(v->capacity * growthRate + 1);
        ValueType *p = (ValueType *)realloc(v->data, newsiz * sizeof(ValueType));

        if(!p)
            return -1;

        v->capacity = newsiz;
        v->data = p;
    }

    // Theres space
    v->data[v->size] = item;
    return v->size++;
}