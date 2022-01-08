#include <stdio.h>

int main()
{
    int n, i, *ptr;
    printf("\n ENTER THE NUMBER OF USN WANT TO ENTER->");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("\n YOUR MEMORY IS FULL");
    }
    printf("\n ENTER THE USN->");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    printf("\n THE USN ENTERED ARE->");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(ptr + i));
    }
    return 0;
}
