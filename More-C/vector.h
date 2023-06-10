#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Reference: An Introduction to the C Programming Language and Software Design. Tim Bailey
typedef double ValueType;

typedef struct {
 ValueType *data; /* pointer to vector elements */
 int size; /* current size of vector */
 int capacity; /* current reserved memory for vector */
 } Vector;

 /* Vector creation and destruction. */
Vector create_vector(int capacity);

void delete_vector(Vector *v);

 /* Vector access operations. */
int push_back(Vector *v, ValueType item);

#if 0
ValueType pop_back(Vector *v);
ValueType* get_element(Vector *v, int index);

 /* Manual resizing operations. */
int get_size(Vector *v);
int set_size(Vector *v, int size);
int get_capacity(Vector *v);
int set_capacity(Vector *v, int size);

#endif