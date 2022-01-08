#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct BST
{
    int info;
    struct BST *llink, *rlink;
};
typedef struct BST node;

node *create(node *root, int ele)
{
    node *temp, *prev, *cur;
    temp = (node *)malloc(sizeof(node));
    temp->info = ele;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (ele < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (ele < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}

int main()
{
    node *root = NULL;
    int ch, ele;
    while (1)
    {
        printf("\n 1: Create 2: Preorder 3:Inorder 4: Postorder 5:exit:");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the element to be inserted:");
            scanf("%d", &ele);
            root = create(root, ele);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        }
    }
    getch();
    return 0;
}
