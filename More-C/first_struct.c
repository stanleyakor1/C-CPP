#include <stdio.h>
#include <stdlib.h>

struct Point{
    int x;
    int y;
} p1, p2,p3; /*Define three variable of type point*/

//or
//struct Point p1,p2,p3
//struct Point topleft = { 320, 0 };

#if 0
int main(int argc, char ** argv)
{
    struct Point toleft;

    toleft.x = 0;
    toleft.y = 320;
    return 0;
}
#endif

struct Rectangle 
{
    struct Point toleft;
    struct Point bottomright;
};
//struct Rectangle rect;
//rect.topleft.x = 50;

int main(void)
{
    struct Rectangle rect, *ptr = &rect;

    ptr->bottomright.x = 5;
    ptr->bottomright.y = 0;
}