#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *top = NULL;

void push(int data);
void pop();
void peek();
void Empty();
void display();


int main()
{
    int c, temp;

    do
    {
        printf("1 push, 2 pop, 3 peek, 4 if empty, 5 display, 6 exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1: 
                printf("Enter data: ");
                scanf("%d", &temp);

                push(temp);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                Empty();
                break;
            case 5: 
                display();
                break;
            case 6:
                break;
            default:
                printf("Try again\n");
                break;
        }
    }while(c != 6);

    return 0;
}

void push(int data)
{
    node *newN = (node *)malloc(sizeof(node));
    newN->data = data;

    if (top == NULL) newN->next = NULL;
    else newN->next = top;

    top = newN;
}

void pop()
{
    node *temp = top;
    top = top->next;
    printf("Popped: %d", temp->data);
    free(temp);
}

void peek()
{
    if (top != NULL) printf("Top: %d\n", top->data);
    else printf("Stack is empty.\n");
}

void Empty()
{
    if (top == NULL) printf("Stack is empty.\n");
    else printf("It is not empty.\n");
}

void display()
{
    node *temp = top;
    
    printf("Displaying stack starting from top: \n");
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}