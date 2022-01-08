#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE *start = NULL;

int menu()
{
    int ch;

    system("cls");

    printf("\n 1.Create a list ");
    printf("\n--------------------------");
    printf("\n 2.Insert a node at beginning ");
    printf("\n 3.Insert a node at end");

    printf("\n--------------------------");
    printf("\n 4.Delete a node from beginning");
    printf("\n 5.Delete a node from Last");

    printf("\n--------------------------");
    printf("\n 6.Displaying the list");

    printf("\n--------------------------");
    printf("\n 7.Exit ");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

NODE *getnode()
{
    NODE *newnode;

    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\n Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

void createlist(int n)
{
    int i;
    NODE *newnode, *temp;

    for (i = 0; i < n; i++)
    {
        newnode = getnode();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void display()
{
    NODE *temp;

    temp = start;
    printf("\n The contents of List (Left to Right): \n");
    if (start == NULL)
    {
        printf("\n Empty List");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
    }
}

void insert_at_beg()
{
    NODE *newnode;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}

void insert_at_end()
{
    NODE *newnode, *temp;

    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void delete_at_beg()
{
    NODE *temp;

    if (start == NULL)
    {
        printf("\n No nodes are exist..");
        return;
    }
    else
    {
        temp = start;
        start = temp->next;
        printf("\n Node deleted %d", temp->data);
        free(temp);
    }
}

void delete_at_last()
{

    NODE *temp, *prev;

    if (start == NULL)
    {
        printf("\n Empty List..");
        return;
    }
    else
    {
        temp = start;
        prev = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("\n Node deleted %d", temp->data);
        free(temp);
    }
}

void main(void)
{
    int ch, n;

    while (1)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            if (start == NULL)
            {
                printf("\n Number of nodes you want to create: ");
                scanf("%d", &n);
                createlist(n);
                printf("\n List created..");
            }
            else
                printf("\n List is already created..");
            break;
        case 2:
            insert_at_beg();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            delete_at_beg();
            break;
        case 5:
            delete_at_last();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        }
        getch();
    }
}
