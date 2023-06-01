#include <stdio.h>
#include <stdlib.h>

// recursively print a string

void _recurs_print(char *s)
{
    if (*s == '\0')
    {
        printf("%c",*s);
        return;
    }
    printf("%c",*s);
    s++;
    _recurs_print(s);
        
    
}

int main(int argc, char ** argv)
{
    char *s = "Stanley";
    _recurs_print(s);
    printf("\n");
    return (0);
}