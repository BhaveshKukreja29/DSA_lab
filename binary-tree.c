#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *kid1;
	struct node *kid2;
}node;

node *root;

void insert();
void delete();
void traverse(node * parent);
void search();
void leafnode();
void height();
void depth();

int main()
{
	int c;
	
	while(c != 8)
	{
		printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to traverse\nEnter 4 to search");
		printf("Enter 5 to see leafnode\n Enter 6 to check height\nEnter 7 to check depth");
		printf("Enter 8 to exit\n");
		
		printf("Enter choice: ");
		scanf("%d", &c);
		
		switch(c)
		{
			case 1:
				insert();
				traverse(root);
				break;
			case 2:
				
				traverse(root);
				break;
			case 3:
				traverse(root);
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:

				break;
			case 8:
				break;
			default:
				printf("Invalid choice");
				break;
		}
	}
}

void insert()
{
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	
	if (root == NULL)
	{
		node *temp = (node *)malloc(sizeof(node));
		temp -> data = data;
		temp -> kid1 = NULL;
		temp ->kid2 = NULL;
		
		root = temp;
	}
	
	else
	{
		node *temp = root;
		node *track = root;
		
		while(temp!= NULL)
		{
			if (data > temp -> data)
			{
				track = temp;
				temp = temp->kid1;
			}
			else if (data < temp -> data)
			{
				track = temp;
				temp = temp->kid2;
			}
			else
			{
				printf("\nRoot already exists\n");
				return;
			}
		}
		
		temp = (node *)malloc(sizeof(node));
		temp -> data = data;
		temp -> kid1 = NULL;
		temp -> kid2 = NULL;
		
		if ((temp -> data) > (track -> data)) track -> kid1 = temp;
		else track -> kid2 = temp; 
	}
}

void traverse(node *parent)
{
	if ((parent->kid2 == NULL) && (parent->kid1 == NULL))
	{
		return;
	}
	
	if (parent->kid2 != NULL)
	{
		traverse(parent->kid2);
	}
	else if (parent->kid1 != NULL)
	{
		printf("%d", parent->data);
		traverse(parent->kid1);
	}	
}
