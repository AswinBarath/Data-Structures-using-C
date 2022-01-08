#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct dlinklist
{
    struct dlinklist *left;
    int data;
    struct dlinklist *right;
};
typedef struct dlinklist NODE;
NODE *start = NULL;

NODE *getnode()
{
    NODE *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int menu()
{
    int ch;
    clrscr();
    printf("\n 1.Create");
    printf("\n------------------------------");
    printf("\n 2. Insert a node at beginning ");
    printf("\n 3. Insert a node at end");

    printf("\n------------------------------");
    printf("\n 4. Delete a node from beginning");
    printf("\n 5. Delete a node from Last");

    printf("\n------------------------------");
    printf("\n 6. Traverse the list from Left to Right ");
    printf("\n 7. Traverse the list from Right to Left ");
    printf("\n------------------------------");
    printf("\n 8.Exit");

    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void createlist(int n)
{
    int i;
    NODE *newnode, *temp;

    for (i = 0; i < n; i++)
    {
        newnode = getnode();
        if (start == NULL)
            start = newnode;
        else
        {
            temp = start;
            while (temp->right)
                temp = temp->right;
            temp->right = newnode;
            newnode->left = temp;
        }
    }
}

void display_left_to_right()
{
    NODE *temp;
    temp = start;
    printf("\n The contents of List: ");
    if (start == NULL)
        printf("\n Empty List");
    else
    {
        while (temp != NULL)
        {
            printf("\t %d ", temp->data);
            temp = temp->right;
        }
    }
}

void display_right_to_left()
{
    NODE *temp;
    temp = start;
    printf("\n The contents of List: ");
    if (start == NULL)
        printf("\n Empty List");
    else
    {
        while (temp->right != NULL)
            temp = temp->right;
    }
    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->left;
    }
}

void dll_insert_beg()
{
    NODE *newnode;
    newnode = getnode();
    if (start == NULL)
        start = newnode;
    else
    {
        newnode->right = start;
        start->left = newnode;
        start = newnode;
    }
}

void dll_insert_end()
{
    NODE *newnode, *temp;

    newnode = getnode();
    if (start == NULL)
        start = newnode;
    else
    {
        temp = start;
        while (temp->right != NULL)
            temp = temp->right;

        temp->right = newnode;
        newnode->left = temp;
    }
}

void dll_delete_beg()
{
    NODE *temp;

    if (start == NULL)
    {
        printf("\n Empty list");
        getch();
        return;
    }
    else
    {
        temp = start;
        start = start->right;
        start->left = NULL;
        free(temp);
    }
}

void dll_delete_last()
{
    NODE *temp;
    if (start == NULL)
    {
        printf("\n Empty list");
        getch();
        return;
    }
    else
    {
        temp = start;
        while (temp->right != NULL)
            temp = temp->right;

        temp->left->right = NULL;
        free(temp);
        temp = NULL;
    }
}

void main(void)
{
    int ch, n;

    system("sys");

    while (1)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            printf("\n Enter Number of nodes to create: ");
            scanf("%d", &n);
            createlist(n);
            printf("\n List created..");
            break;
        case 2:
            dll_insert_beg();
            break;
        case 3:
            dll_insert_end();
            break;
        case 4:
            dll_delete_beg();
            break;
        case 5:
            dll_delete_last();
            break;
        case 6:
            display_left_to_right();
            break;
        case 7:
            display_right_to_left();
            break;
        case 8:
            exit(0);
        }
        getch();
    }
}
