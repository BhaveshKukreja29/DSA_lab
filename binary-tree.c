#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *kid1;
    struct node *kid2;
} node;

node *root = NULL;

void add();
void remove_node();
void traverse_inorder(node *parent);
void traverse_preorder(node *parent);
void traverse_postorder(node *parent);
void find();
int count_nodes(node *parent);
int count_leafnodes(node *parent);
int tree_height(node *parent);
node *get_minimum(node *parent);
node *get_maximum(node *parent);
node *delete_node(node *parent, int key);
int search_node(node *parent, int key);

int main() 
{
    int c;

    while (c != 10)
    {
        printf("Enter 1 to add\nEnter 2 to remove\nEnter 3 for inorder traversal\n");
        printf("Enter 4 for preorder traversal\nEnter 5 for postorder traversal\n");
        printf("Enter 6 to find an element\nEnter 7 to count total nodes\n");
        printf("Enter 8 to count leaf nodes\nEnter 9 for tree height\n");
        printf("Enter 10 to exit\n");

        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c)
        {
            case 1:
                add();
                break;
            case 2:
                remove_node();
                break;
            case 3:
                traverse_inorder(root);
                printf("\n");
                break;
            case 4:
                traverse_preorder(root);
                printf("\n");
                break;
            case 5:
                traverse_postorder(root);
                printf("\n");
                break;
            case 6:
                find();
                break;
            case 7:
                printf("Total nodes: %d\n", count_nodes(root));
                break;
            case 8:
                printf("Total leaf nodes: %d\n", count_leafnodes(root));
                break;
            case 9:
                printf("Tree height: %d\n", tree_height(root));
                break;
            case 10:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void add() 
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->kid1 = NULL;
    new_node->kid2 = NULL;

    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        node *temp = root;
        node *parent = NULL;

        while (temp != NULL)
        {
            parent = temp;
            if (data < temp->data)
            {
                temp = temp->kid1;
            }
            else
            {
                temp = temp->kid2;
            }
        }

        if (data < parent->data)
        {
            parent->kid1 = new_node;
        }
        else
        {
            parent->kid2 = new_node;
        }
    }
}

void remove_node() 
{
    int key;
    printf("Enter value to remove: ");
    scanf("%d", &key);
    root = delete_node(root, key);
}

node *delete_node(node *parent, int key) 
{
    if (parent == NULL)
    {
        return parent;
    }
    
    if (key < parent->data)
    {
        parent->kid1 = delete_node(parent->kid1, key);
    }
    else if (key > parent->data)
    {
        parent->kid2 = delete_node(parent->kid2, key);
    }
    else
    {
        if (parent->kid1 == NULL)
        {
            node *temp = parent->kid2;
            free(parent);
            return temp;
        }
        else if (parent->kid2 == NULL)
        {
            node *temp = parent->kid1;
            free(parent);
            return temp;
        }

        node *temp = get_minimum(parent->kid2);
        parent->data = temp->data;
        parent->kid2 = delete_node(parent->kid2, temp->data);
    }
    return parent;
}

node *get_minimum(node *parent) 
{
    while (parent && parent->kid1 != NULL)
    {
        parent = parent->kid1;
    }
    return parent;
}

node *get_maximum(node *parent) 
{
    while (parent && parent->kid2 != NULL)
    {
        parent = parent->kid2;
    }
    return parent;
}

void traverse_inorder(node *parent) 
{
    if (parent == NULL) return;
    traverse_inorder(parent->kid1);
    printf("%d ", parent->data);
    traverse_inorder(parent->kid2);
}

void traverse_preorder(node *parent) 
{
    if (parent == NULL) return;
    printf("%d ", parent->data);
    traverse_preorder(parent->kid1);
    traverse_preorder(parent->kid2);
}

void traverse_postorder(node *parent) 
{
    if (parent == NULL) return;
    traverse_postorder(parent->kid1);
    traverse_postorder(parent->kid2);
    printf("%d ", parent->data);
}

void find() 
{
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);
    if (search_node(root, key))
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}

int search_node(node *parent, int key) 
{
    if (parent == NULL) return 0;
    if (key == parent->data) return 1;
    if (key < parent->data) return search_node(parent->kid1, key);
    return search_node(parent->kid2, key);
}

int count_nodes(node *parent) 
{
    if (parent == NULL) return 0;
    return 1 + count_nodes(parent->kid1) + count_nodes(parent->kid2);
}

int count_leafnodes(node *parent) 
{
    if (parent == NULL) return 0;
    if (parent->kid1 == NULL && parent->kid2 == NULL) return 1;
    return count_leafnodes(parent->kid1) + count_leafnodes(parent->kid2);
}

int tree_height(node *parent) 
{
    if (parent == NULL) return -1;
    int left_height = tree_height(parent->kid1);
    int right_height = tree_height(parent->kid2);
    return (left_height > right_height ? left_height : right_height) + 1;
}
