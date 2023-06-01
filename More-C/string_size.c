#include <stdio.h>
#include <stdlib.h>

int  _strlen(char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        len++;
        s++;
    }
    return (len);
}

int main(int argc, char ** argv)
{
    char *name = "Stanley";

    int len = _strlen(name);

    printf("String length = %d\n", len);

}