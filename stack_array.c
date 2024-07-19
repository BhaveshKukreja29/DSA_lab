#include <stdio.h>

#define max 10

int top = -1;
int stack[max] = {0};

int isEmpty();
int isFull();
void push(int n, int arr[]);
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
				int z;
				
				printf("\nHow many elements do you want to insert: %d\n\n", n);
				scanf("%d", &n);
				
				if (10 - n - (top + 1) > -1)
				
				for (int k = 0; k < n; k++)
				{
					printf("Enter element %d: ", k + 1); 
					scanf("%d", &z);
					push(z);
				}
				
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

void push(int n, int arr[])
{
	if ()
	{
		
	}
	
	else
	{
		printf("\n\nError. Not enough space\n\n.");
	}
}

void pop()
{
	if (isEmpty() == 0)
	{
		printf("\n\nThe element deleted was: %d\n\n", stack[top]); 
		top--;
		return;
	}
	
	printf("\n\nThe stack is empty, cannot delete anything.\n\n");
	return;
}


void peek()
{
	if (isEmpty() == 0)
	{
		printf("\n\nThe top element currently: %d\n\n", stack[top]);
		return;
	}
	printf("\n\nStack is empty\n\n");
	return;
}


void display()
{
	printf("\n\nThis is how the stack looks starting from the top.\n\n");
	
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
	
	printf("\n\n");
	
	return;
}
