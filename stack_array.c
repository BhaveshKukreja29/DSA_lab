#include <stdio.h>

#define max 10

int top = -1;
int stack[max] = {0};

int isEmpty();
int isFull();
void push(int n);
void pop();
void peek();
void display();


int main()
{
	int ch;
	
	do{
		printf("Enter 1 to insert an element. \nEnter 2 to delete the top element.\nEnter 3 to view the top element.\n");
		printf("Enter 4 to check if empty. \nEnter 5 to check if full.\nEnter 6 to exit.\n ");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				int n;
				printf("Enter your element: ");
				scanf("%d", &n);
				
				push(n);
				break;
			
			case 2:
				pop();
				break;
			
			case 3:
				peek();
				break;
			case 4:
				int s1 = isEmpty();
				
				if (s1 == 1)
				{
					printf("Stack is indeed empty.\n\n");
				}
				
				else
				{
					printf("Stack has some elements. \n\n");
				}
				
				break;
			case 5:
				int s2 = isFull();
				
				if (s2 == 1)
				{
					printf("Stack is Full.\n\n");
				}
				
				else
				{
					printf("Stack has space. \n\n");
				}
				
				break;
			case 6:
				break;
			
			default:
				printf("Error, please input an integer from 1 to 6.");
		}
	}while(ch != 6);
}

int isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	
	return 0;
}

int isFull()
{
	if (top == max - 1)
	{
		return 1;
	}

	return 0;
}

void push(int n)
{
	if (isFull() == 0)
	{
		stack[++top] = n;
		printf("\nSuccesfully pushed %d to the stack.\n\n", n); 
	}
	
	else
	{
		printf("Error. Stack is full.");
	}
}

void pop()
{
	if (isEmpty() == 0)
	{
		printf("\nThe element deleted was: %d\n\n", stack[top]); 
		top--;
		return;
	}
	
	printf("The stack is empty, cannot delete anything.");
	return;
}


void peek()
{
	if (isEmpty() == 0)
	{
		printf("\nThe top element currently: %d\n\n", stack[top]);
		return;
	}
	printf("\n Stack is empty\n\n");
	return;
}


void display()
{
	printf("\nThis is how the stack looks starting from the top.\n\n");
	
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
	
	printf("\n\n");
	
	return;
}
