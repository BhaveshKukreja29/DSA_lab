#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *top = NULL;

void push(int data);
int pop();
int peek();
int isEmpty();
void display();

int main()
{
    int choice, data;
    
    do
    {
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to check if empty\n");
        printf("Enter 5 to display stack\n");
        printf("Enter 6 to exit\n");
        printf("/nEnter your choice: ");

        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);

                push(data);
                display();
                break;

            case 2:
                data = pop();
                if (data == -1) printf("Stack is empty.\n");
                else printf("Popped: %d\n", data);

                display();
                break;

            case 3:
                data = peek();

                if (data == -1) printf("Stack is empty.\n");
                else printf("Top element: %d\n", data);

                break;

            case 4:
                if (isEmpty()) printf("Stack is empty.\n");
                else printf("Stack is not empty.\n");

                break;

            case 5:
                display();
                break;
        }
    } while(choice != 6);

    return 0;
}

void push(int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if(top == NULL) return -1;

    int data = top->data;
    node *temp = top;
    top = top->next;

    free(temp);
    return data;
}

int peek()
{
    if(top == NULL) return -1;
    return top->data;
}

int isEmpty()
{
    return top == NULL;
}

void display()
{
    if(top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    node *temp = top;
    
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
