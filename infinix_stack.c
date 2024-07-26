#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 10

char in[50];
char po[50];
int top = -1;
char stack[max] = {0};


int pres(char a, char b);
int isEmpty();
int isFull();
void push(char c, char arr[]);
void pop();
void peek();
void display();
int pre(char a);


int main()
{
	
	printf("Enter your input: ");
	scanf("%s", in);
	
	int j = 0;
	for (int i = 0; in[i] != '\0'; i++)
	{
		if ((in[i] == '{' || in[i] == '[' || in[i] == '('))
		{
			push(in[i], stack);
		}
		
		else if (isalnum(in[i]))
		{
			po[j] = in[i];
			j++;
		}
		
		else if (in[i] ==  ')')
		{
			while (stack[top] != '(')
			{
				po[j++] = stack[top];
				pop();
			}
			pop();
		}
		
		else if (in[i] ==  '}')
		{
			while (stack[top] != '{')
			{
				po[j++] = stack[top];
				pop();
			}
			pop();
		}
		
		else if (in[i] ==  ']')
		{
			while (stack[top] != '[')
			{
				po[j++] = stack[top];
				pop();
			}
			pop();
		}
		
		else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '^' || in[i] == '%')
		{
			int u = pre(in[i]);
			int st = pre(stack[top]);
			
			if (u > st)
			{
				stack[++top] = in[i];
			}
			
			else if (u == st)
			{
				po[j++] = stack[top];
				stack[top] = in[i];
			}
			
			else
			{
				po[j++] = stack[top];
				stack[top] = in[i];
			}
		}
	}
	
	while (top >= 0)
	{
		po[j++] = stack[top];
		pop();
	}
	
	po[j] = '\0';
	
	for (int k = 0; po[k] != '\0'; k++)
	{
		printf("%c", po[k]);	
	}
}

int pre(char a)
{
	if (a == '+' || a == '-')
	{
		return 0;
	}
	
	else if (a == '*' || a == '/')
	{
		return 1;
	}
	
	else if (a == '^' || a == '%')
	{
		return 2;
	}
	
	return -1;
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

void push(char c, char arr[])
{
	if (isFull() == 0)
	{
		arr[++top] = c; 	
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
		top--;
		return;
	}
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
