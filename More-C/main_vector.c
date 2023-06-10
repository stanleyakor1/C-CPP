
//#include "vector.h"
#include "vector_class.c"

int main(void)
{

    Vector v;

    v = create_vector(1);

    int check = push_back(&v,(double)0.5);
    int check1 = push_back(&v,(double)0.2);

    printf("check = %d, check = %d\n", check, check1);

    return 0;
}