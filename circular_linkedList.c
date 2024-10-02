#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
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
                printf("1 to insert at beggining, 2 to insert before some node, 3 to insert after some node.\n");
                printf("Enter 4 for insert at end.\n");
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
                delete (temp);

                traverse();
                break;

            case 3:
                traverse();
                break;

            case 4:
                break;
        }
    }
    while (c < 4);

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

    do
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
        count++;
    }
    while (temp != head);

    if (count > 0)
        printf("\n^");

    for (int c = 0; c < count; c++)
    {
        printf("-----");
    }
    printf("|");
    printf("\n\nNumber of nodes is: %d\n\n", count);
    return;
}

void insert(int data)
{
    if (head == NULL)
    {
        head = (node *) malloc(sizeof(node));
        head->data = data;
        head->next = head;
        return;
    }
    else
    {
        node *temp = (node *) malloc(sizeof(node));
        temp->data = data;
        temp->next = head;

        node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = temp;
        head = temp;
        return;
    }
}

void insertEnd(int data)
{
    if (head == NULL)
	{
		head = (node *)malloc(sizeof(node));

		head->data = data;
		head->next = NULL;

		return;
	}
	
	else
	{
		node *temp = head->next;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        node *store = (node *)malloc(sizeof(node));
		store->data = data;
		store->next = head;
        temp->next = store;

		return;
	}
}

void insert_where(int data, int tempref, int choice)
{
    if (head == NULL)
    {
        head = (node *) malloc(sizeof(node));
        head->data = data;
        head->next = head;
        return;
    }
    else
    {
        node *temp = head;
        node *store;

        if (choice == 2)
        {
            do
            {
                if (temp->next->data == tempref)
                    break;
                temp = temp->next;
            }
            while (temp->next != head);

            if (temp->next == head)
            {
                printf("Couldn't find the reference.\n\n");
                return;
            }
        }
        else
        {
            do
            {
                if (temp->data == tempref)
                    break;
                temp = temp->next;
            }
            while (temp != head);

            if (temp->next == head && temp->data != tempref)
            {
                printf("Couldn't find the reference.\n\n");
                return;
            }
        }

        store = (node *) malloc(sizeof(node));
        store->data = data;
        store->next = temp->next;
        temp->next = store;

        return;
    }
}

void delete(int data)
{
    if (head == NULL)
    {
        printf("Linked list is empty, cannot delete.\n\n");
        return;
    }
    else
    {
        node *temp = head;
        node *prev = NULL;
        while (temp->next != head && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data != data)
        {
            printf("Element not present in the linked list.\n\n");
            return;
        }
        else if (temp == head)
        {
            if (head->next == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                prev = head;
                while (prev->next != head)
                {
                    prev = prev->next;
                }
                prev->next = head->next;
                free(head);
                head = prev->next;
            }
        }
        else
        {
            prev->next = temp->next;
            free(temp);
        }
        return;
    }
}

void deletell()
{
    if (head == NULL)
    {
        printf("There is no linked list to delete.\n");
        return;
    }
    else
    {
        node *temp = head;
        node *next;

        do
        {
            next = temp->next;
            free(temp);
            temp = next;
        }
        while (temp != head);

        head = NULL;
        printf("Linked list deleted.\n");
    }
}
