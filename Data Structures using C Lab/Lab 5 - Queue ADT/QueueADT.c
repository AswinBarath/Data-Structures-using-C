#include <stdio.h>
#include <conio.h>
#define MAX 6

void insertQ(int Q[], int *front, int *rear)
{
    int data;
    if ((*rear) == MAX)
    {
        printf("\n Linear Queue is full");
        return;
    }

    printf("\n Enter data: ");
    scanf("%d", &data);

    Q[*rear] = data;
    (*rear)++;

    printf("\n Data Inserted in the Queue ");
}

void deleteQ(int Q[], int *front, int *rear)
{
    if (*rear == *front)
    {
        printf("\n\n Queue is Empty..");
        *rear = *front = 0;
        return;
    }
    else
    {
        printf("\n Deleted element from Queue is %d", Q[*front]);
        (*front)++;

        if (*front == *rear)
            *front = *rear = 0;
    }
}

void displayQ(int Q[], int *front, int *rear)
{
    int i;

    if (*front == *rear)
    {
        printf("\n\n\t Queue is Empty");
        return;
    }
    else
    {
        printf("\n Elements in Queue are: ");
        for (i = *front; i < *rear; i++)
        {
            printf("%d\t", Q[i]);
        }
    }
}

int menu()
{
    int ch;

    printf("\n \tQueue operations using ARRAY..");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");

    scanf("%d", &ch);
    return ch;
}

void main()
{
    int ch;

    int Q[MAX];
    int *front = 0, *rear = 0;

    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            insertQ(Q, &front, &rear);
            break;
        case 2:
            deleteQ(Q, &front, &rear);
            break;
        case 3:
            displayQ(Q, &front, &rear);
            break;
        case 4:
            exit(0);
        }
    } while (1);
}
