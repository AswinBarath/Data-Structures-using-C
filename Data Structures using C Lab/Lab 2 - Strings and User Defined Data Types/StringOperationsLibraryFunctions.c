#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[10], b[10], s[10];
    int x, y, z;
    printf("\n enter the 1st string");
    gets(a);
    printf("\n enter the second string");
    gets(b);
    x = strlen(a);
    y = strlen(b);
    z = strcmp(a, b);
    strcpy(a, b);
    strrev(b);
    printf("\n string length =%d", x);
    printf("\n string length =%d", y);
    printf("\n after comparing =%d", z);
    printf("\n string rev =%s", a);
    return 0;
}
