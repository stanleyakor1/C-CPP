#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Delete a string of characters or set the char pointer to null;
//#if 0
void _delete_string(char * s)
{
    if(*s == '\0')
    {
        return;
    }
    *s = '\0';
    _delete_string(s++);
    
}
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
    char *s = malloc(sizeof(char)*8);
    
    copy(s,"Stanley");

    _delete_string(s);

    if(*s == '\0')
    {
        printf("Deletion succesful!\n");
    }
        

    free(s);
    return (0);
}
//#endif
