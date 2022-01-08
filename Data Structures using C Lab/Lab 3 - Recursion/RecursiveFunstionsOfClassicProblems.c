#include <stdio.h>
#include <conio.h>

int fib(int n)
{
    int x;
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;

    x = fib(n - 1) + fib(n - 2);
    return (x);
}

int sum(int n)
{

    if (n <= 1)
        return 1;
    return n + sum(n - 1);
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

void main()
{
    int a[20], n, i, sum1, fact;

    printf("enter the value for n:\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        a[i] = fib(i);

    printf("\nfibonacci series\n ");
    for (i = 1; i <= n; i++)
        printf(" -->%d", a[i]);

    printf("\n sum of natural numbers = ");
    sum1 = sum(n);
    printf("%d", sum1);

    printf("\n factorial of %d = ", n);
    fact = factorial(n);
    printf("%d", fact);

    getch();
}
