#include <stdio.h>
int main()
{
    int a, b;
    printf("\n enter the value of a= ");
    scanf("%d", &a);
    printf("\n enter the value of b=");
    scanf("%d", &b);
    printf("\n values of a and b before swaping=%d and  %d", a, b);
    swap(&a, &b);

    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    printf("\n values of a and b after swaping=%d and  %d", *x, *y);
}
