#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *rear = NULL;
node *front = NULL;

void enq(int data);
void deq();
void frontt();
void display();

int main()
{
    int c, temp;

    do 
    {
        printf("1 enq, 2 deq, 3 front, 4 disp, 5 exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &temp);

                enq(temp);
                break;
            case 2: 
                deq();
                break;
            case 3:
                frontt();
                break;
            case 4: 
                display();
                break;
            case 5:
                break;
            default:
                printf("try again\n");
                break;
        }
    }while (c != 5);

    return 0;
}

void enq(int data)
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
void deq()
{
    if (front == NULL) printf("Queue empty.\n");

    int data = front->data;

    node *temp = front;
    front = front->next;
    free(temp);

    if (front == NULL) rear = NULL;
    printf("Dequeued: %d", data);
}
void frontt()
{
    if (front == NULL) printf("Queue is empty.\n");
    else printf("Front: %d", front->data);
}
void display()
{
    node *temp = front;
    printf("Queue is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}