#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 6

int menu()
{
    int ch;

    printf("\n -----------**********-------------\n");
    printf("\n ....Stack operations using ARRAY.... ");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Push ");
    printf("\n 2. Pop ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");

    printf("\n Enter your choice: ");
    scanf("%d", &ch);

    return ch;
}

void display(int stack[], int *top)
{
    int i;
    if ((*top) == 0)
    {
        printf("\n\nStack empty..");
        return;
    }
    else
    {
        printf("\n\nElements in stack:");
        for (i = (*top) - 1; i >= 0; i--)
            printf("\n%d", stack[i]);
    }
}

void pop(int stack[], int *top)
{
    if (*top == 0)
    {
        printf("\n\nStack Underflow..");
        return;
    }
    else
        printf("\n\npopped element is: %d ", stack[--(*top)]);
}

void push(int stack[], int *top)
{
    int data;
    if (*top == MAX)
    {
        printf("\n\nStack Overflow..");
        return;
    }
    else
    {
        printf("\n\nEnter data: ");
        scanf("%d", &data);

        stack[(*top)] = data;
        *top = *top + 1;

        printf("\n\nData Pushed into the stack");
    }
}

void main()
{
    int ch;
    int stack[MAX];
    int(*top) = 0;

    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            push(stack, &top);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            display(stack, &top);
            break;
        case 4:
            exit(0);
        }
        getch();
    } while (1);
}
 
