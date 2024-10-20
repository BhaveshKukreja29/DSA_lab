#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *root = NULL;

node *insert(node *parent, int data);
node *delete(node *parent, int data);
node *get_min(node *parent);
void search(node * parent, int data);
void preorder(node *parent);
void inorder(node *parent);
int count(node *parent);
int countLeaf(node *parent);
int countInternal(node *parent);

int main()
{
    int c;
    int temp;

    do{
        printf("Enter 1 to insert, 2 to search, 3 to traverse, 4 to count.\n");
        printf("Enter 5 to delete\n");
        printf("Enter 6 for inorder\n");
        printf("7 for leaf, 8 for internal\n");
        printf("Enter 9 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("Enter integer: ");
                scanf("%d", &temp);
                root = insert(root, temp);
                break;
            case 2:
                printf("Enter integer to search: ");
                scanf("%d", &temp);
                search(root, temp);
                break;
            case 3:
                preorder(root);
                break;
            case 4: 
                temp = count(root);
                printf("Count is: %d \n\n", temp);
                break;
            case 5:
                printf("Enter the node to be deleted: ");
                scanf("%d", &temp);
                root = delete(root, temp);
                break;
            case 6:
                inorder(root);
                break;

            case 7:
                temp = countLeaf(root);
                printf("Leafs is: %d", temp);
                break;
            case 8:
                temp = countInternal(root);
                printf("Internal is: %d", temp);
                break;
            case 9:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(c != 9);

    return 0;
}

node *insert(node *parent, int data)
{
    if (parent == NULL)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (data == parent->data)
    {
        printf("Node already there\n");
        return parent;
    }

    if (data > parent->data)
    {
        parent->right = insert(parent->right, data);
    }

    else if (data < parent->data)
    {
        parent->left = insert(parent->left, data);
    }

    return  parent;
}

node *delete(node *parent, int data)
{
    if (parent == NULL)
    {
        return NULL;
    }
    if (data < parent->data)
    {
        parent->left = delete(parent->left, data);
        return parent;
    }
    else if (data > parent->data)
    {
        parent->right = delete(parent->right, data);
        return parent;
    }
    else
    {
        if (parent->left == NULL)
        {
            node *temp = parent->right;
            free(parent);
            return temp;
        }
        else if (parent->right == NULL)
        {
            node *temp = parent->left;
            free(parent);
            return temp;
        }
        else
        {
            node *temp = get_min(parent->right);
            parent->data = temp->data;
            parent->right = delete(parent->right, temp->data);
        }

        return parent;
    }
}

node *get_min(node *parent)
{
    while (parent && parent->left != NULL)
    {
        parent = parent->left;
    }
    return parent;
}

void search(node * parent, int data)
{
    if (parent == NULL) printf("Not found.\n");
    else if (parent->data == data) printf("Found.\n");
    else if (data > parent->data) search(parent->right, data);
    else search(parent->left, data);
}
void preorder(node *parent)
{
    if (parent == NULL) return;
    printf("%d ", parent->data);
    preorder(parent->left);
    preorder(parent->right);
}

void inorder(node *parent)
{
    if (parent == NULL) return;
    inorder(parent->left);
    printf("%d", parent->data);
    inorder(parent->right);
}

int count(node *parent)
{
    if (parent == NULL) return 0;
    return 1 + count(parent->left) + count(parent->right);
}

int countLeaf(node *parent)
{
    if (parent == NULL) return 0;
    if (parent->left == NULL && parent->right == NULL) return 1;
    return countLeaf(parent->left) + countLeaf(parent->right);
}

int countInternal(node *parent)
{
    if (parent == NULL) return 0;
    if (parent->left != NULL || parent->right != NULL)
    {
        return 1 + countInternal(parent->left) + countInternal(parent->right);
    }
}