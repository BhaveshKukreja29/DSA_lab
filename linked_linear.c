#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void createll(node *head);
void traverse(node *head);
void insert(node *head, int data);
void delete(node *head,int data);
void deletell(node *head);

int main()
{
	node *head = NULL;
	int c;
	
	do{
		printf("Enter 1 to insert in linked list\n");
		printf("Enter 2 to delete from the linked list\n");
		printf("Enter 3 to traverse the linked list\n");
		printf("Enter 4 to delete the linked list\n");
				
		scanf("%d", &c);
		
		switch(c)
		{
			case 1:
				int temp;
				int length;
				
				printf("Enter the number of nodes: ");
				scanf("%d", &length);
				
				for (int i = 0; i < length; i++)
				{
					printf("Enter your data: ");
					scanf("%d", &temp);
					insert(head, temp);
				}
				
				traverse(head);
				break;
				
			case 2:
				printf("Enter the number of nodes: ");
				scanf("%d", &length);
				
				for (int i = 0; i < length; i++)
				{
					printf("Enter your data to be deleted: ");
					scanf("%d", &temp);
					delete(head, temp);
				}
				traverse(head);
				break;
				
			case 3:
				traverse(head);
				break;
				
			case 4:
				break;
				
		}
				
	}while(c < 4);
	
	deletell(head);
	
	return 0;
}

void createll(node *head)
{
	if (head == NULL)
	{
		head = (node *)malloc(sizeof(node));
	}
}
void traverse(node *head)
{
	int count = 0;
	node *temp;
	printf("This is how the list looks like currently\n\n");
	
	temp = head;
	
	if (temp == NULL)
	{
		printf("Linked list empty");
		return;
	}
	
	while (temp != NULL)
	{
		printf("%d --> ", temp->data);
		temp = temp -> next;
		count++;
	}
	
	printf("Number of nodes is: %d", count);
	return;
}
		 
void insert(node *head, int data)
{
	if (head == NULL)
	{
		createll(head);
		head->data = data;
		head->next = NULL;
		return;
	}
	
	else
	{
		node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (node *)malloc(sizeof(node));
		temp = temp->next;
		temp->data = data;
		temp->next = NULL;
		return;
	}
}
		
void delete(node *head,int data)
{
	if (head == NULL)
	{
		printf("Linked list is empty, cannot delete.\n\n");
		return;
	}
	
	else
	{
		node *temp = head;
		while (temp->next->data != data && temp->next != NULL)
		{
			temp = temp->next;
		}
		
		if (temp->next == NULL)
		{
			printf("Element not present in the linked list.\n\n");
			return;
		}
		
		else if (temp->next->data == data)
		{
			node *temp2 = temp->next;
			temp->next = temp2->next;
			free(temp2);
		}
		return;
	}
}

void deletell(node *head)
{
	if (head == NULL)
	{
		printf("There is no linked list to delete.");
		return;
	}
	
	else
	{
		node *temp = head;
		while (head != NULL)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
		free(temp);
	}
}
