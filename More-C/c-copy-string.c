#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 /*
 
 copy a string pointer into another empty string ponter.
 
 */

void copy(char * x, char * y)
{
 while (*y != '\0')
 {
    *x = *y;
    y++;
    x++;
 }
 *x = '\0';
}
int main(int argc, char ** argv)
{
    char * p;
    char *tee = "holiday";
    int len = strlen(tee) +1;

    p = malloc(sizeof(char) * len);

    if (!p)
    {
        printf("Failed to allocate memory, exiting!!");
        return (1);
    }
    copy(p,tee);

    char * ptr = p; // pointer to iterate over the copied string
   while(*ptr)
   {
    printf("%c",*ptr);
    ptr++;
   }
    printf("\n");

   free(p);
   return (0);

}
