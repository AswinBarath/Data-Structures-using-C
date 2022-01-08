#include <stdio.h>
int main()
{
    int *p;
    int a = 10;
    p = &a;
    printf("\n address of a=%p", &a);
    printf("\n address of p=%p", &p);
    printf("\n value of a=%d", a);
    printf("\n value of pointer p=%d", *p);
    printf("\n value at p=%p", p);
    return 0;
}
