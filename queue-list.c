#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *front = NULL, *rear = NULL;

void enqueue(int data);
int dequeue();
int getFront();
void display();

int main()
{
    int choice, data;
    
    do
    {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to get front\n");
        printf("Enter 4 to display queue\n");
        printf("Enter 5 to exit\n");
        printf("/nEnter your choice: ");

        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);

                enqueue(data);
                display();
                break;

            case 2:
                data = dequeue();
                if (data == -1) printf("Queue is empty.\n");

                else printf("Dequeued: %d\n", data);

                display();
                break;

            case 3:
                data = getFront();

                if (data == -1) printf("Queue is empty.\n");
                
                else printf("Front element: %d\n", data);
                break;

            case 4:
                display();
                break;
        }
    } while(choice != 5);

    return 0;
}

void enqueue(int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    if(front == NULL) return -1;
    int data = front->data;

    node *temp = front;
    front = front->next;

    if(front == NULL) rear = NULL;

    free(temp);
    return data;
}

int getFront()
{
    if(front == NULL) return -1;
    return front->data;
}

void display()
{
    if(front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    node *temp = front;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
