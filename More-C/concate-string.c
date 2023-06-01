#include <stdio.h>
#include <stdlib.h>
// Function to concate strings!
void concate(char *s, char *c)
{
    while(*s)
    {
        s++;
    }
    while(*c)
    {
        *s = *c;
        c++;
        s++;
    }
    *s = '\0';
}

int main(int argc, char ** argv)
{
    char s[100] = "School no be";
    char *c = " scam";
    concate(s,c);

    char *ptr = s;
    while (*ptr != '\0' )
    {
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n");
}