#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct cslinklist
{
    int data;
    struct cslinklist *next;
};
typedef struct cslinklist NODE;
NODE *start = NULL;

int nodectr;

NODE *getnode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

int menu()
{
    int ch;

    system("sys");

    printf("\n 1. Create a list ");
    printf("\n\n--------------------------");
    printf("\n 2. Insert a node at beginning ");
    printf("\n 3. Insert a node at end");

    printf("\n\n--------------------------");
    printf("\n 5. Delete a node from beginning");
    printf("\n 6. Delete a node from Last");

    printf("\n\n--------------------------");
    printf("\n 8. Display the list");
    printf("\n 9. Exit");
    printf("\n\n--------------------------");

    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void createlist(int n)
{
    int i;
    NODE *newnode, *temp;
    nodectr = n;

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
    newnode->next = start; /* last node is pointing to starting node */
}

void display()
{
    NODE *temp;

    temp = start;
    printf("\n The contents of List (Left to Right): ");
    if (start == NULL)
        printf("\n Empty List");
    else
    {
        do
        {
            printf("\t %d ", temp->data);
            temp = temp->next;
        } while (temp != start);

        printf(" X ");
    }
}

void cll_insert_beg()
{
    NODE *newnode, *last;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        last = start;
        while (last->next != start)
            last = last->next;
        newnode->next = start;
        start = newnode;
        last->next = start;
    }
    printf("\n Node inserted at beginning..");
    nodectr++;
}

void cll_insert_end()
{
    NODE *newnode, *temp;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != start)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = start;
    }
    printf("\n Node inserted at end..");
    nodectr++;
}

void cll_delete_beg()
{
    NODE *temp, *last;
    if (start == NULL)
    {
        printf("\n No nodes exist..");
        getch();
        return;
    }
    else
    {
        last = temp = start;

        while (last->next != start)
            last = last->next;

        start = start->next;
        last->next = start;
        free(temp);
        nodectr--;

        printf("\n Node deleted..");
        if (nodectr == 0)
            start = NULL;
    }
}

void cll_delete_last()
{
    NODE *temp, *prev;
    if (start == NULL)
    {
        printf("\n No nodes exist..");
        getch();
        return;
    }
    else
    {
        temp = start;
        prev = start;
        while (temp->next != start)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = start;
        free(temp);
        nodectr--;

        if (nodectr == 0)
            start = NULL;
        printf("\n Node deleted..");
    }
}

void main(void)
{
    int result;
    int ch, n;
    system("sys");
    while (1)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            if (start == NULL)
            {
                printf("\n Enter Number of nodes to create: ");
                scanf("%d", &n);
                createlist(n);
                printf("\nList created..");
            }
            else
                printf("\n List is already Exist..");
            break;
        case 2:
            cll_insert_beg();
            break;
        case 3:
            cll_insert_end();
            break;
        case 4:
            cll_delete_beg();
            break;
        case 5:
            cll_delete_last();
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
