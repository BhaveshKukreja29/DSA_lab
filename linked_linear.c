#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void traverse();
void insert(int data);
void insert_where(int temp, int tempref, int choice);
void insertEnd(int data);
void delete(int data);
void deletell();

int main() 
{
    int c;

    do 
    {
        printf("Enter 1 to insert in linked list\n");
        printf("Enter 2 to delete from the linked list\n");
        printf("Enter 3 to traverse the linked list\n");
        printf("Enter 4 to delete the linked list\n");

        scanf("%d", &c);

        int temp;
        int choice;
        int tempref;
        switch (c) 
        {
            case 1:
                printf("1 to insert at beginning, 2 to insert before some node, 3 to insert after some node.\n");
                printf("4 to insert at end.\n");
                printf("Enter the choice: ");
                scanf("%d", &choice);

                if (choice == 2 || choice == 3) 
                {
                    printf("Enter the reference node: ");
                    scanf("%d", &tempref);

                    printf("Enter your data: ");
                    scanf("%d", &temp);

                    insert_where(temp, tempref, choice);
                } 
                else if (choice == 4) 
                {
                    printf("Enter your data: ");
                    scanf("%d", &temp);
                    insertEnd(temp);
                } 
                else 
                {
                    printf("Enter your data: ");
                    scanf("%d", &temp);

                    insert(temp);
                }

                traverse();
                break;

            case 2:
                printf("Enter your data to be deleted: ");
                scanf("%d", &temp);
                delete(temp);

                traverse();
                break;

            case 3:
                traverse();
                break;

            case 4:
                break;
        }

    } while (c < 4);

    deletell();

    return 0;
}

void traverse() 
{
    int count = 0;
    node *temp = NULL;
    printf("This is how the list looks like currently\n\n");

    temp = head;

    if (temp == NULL) 
    {
        printf("Linked list empty\n\n");
        return;
    }

    while (temp != NULL) 
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Number of nodes is: %d\n\n", count);
}

void insert(int data) 
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertEnd(int data) 
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) 
    {
        head = temp;
        return;
    }

    node *ptr = head;
    while (ptr->next != NULL) 
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insert_where(int data, int tempref, int choice) 
{
    node *temp = head, *store;

    if (choice == 2) 
    {
        while (temp->next != NULL && temp->next->data != tempref) 
        {
            temp = temp->next;
        }
        if (temp->next == NULL) 
        {
            printf("Couldn't find the reference.\n\n");
            return;
        }
    } 
    else 
    {
        while (temp != NULL && temp->data != tempref) 
        {
            temp = temp->next;
        }
        if (temp == NULL) 
        {
            printf("Couldn't find the reference.\n\n");
            return;
        }
    }

    store = (node *)malloc(sizeof(node));
    store->data = data;
    store->next = temp->next;
    temp->next = store;
}

void delete(int data) 
{
    if (head == NULL) 
    {
        printf("Linked list is empty, cannot delete.\n\n");
        return;
    }

    if (head->data == data) 
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    node *temp = head;
    while (temp->next != NULL && temp->next->data != data) 
    {
        temp = temp->next;
    }

    if (temp->next == NULL) 
    {
        printf("Element not present in the linked list.\n\n");
        return;
    }

    node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void deletell() 
{
    node *temp = head;
    while (head != NULL) 
    {
        head = head->next;
        free(temp);
        temp = head;
    }
}
