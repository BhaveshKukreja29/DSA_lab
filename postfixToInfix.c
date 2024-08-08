#include <stdio.h>
#include <ctype.h>

#define max 10

char s[50];
int top = -1;
int stack[max] = {0};

int isEmpty();
int isFull();
void push(int n);
void pop();
void eval(char s[]);
int power(int base, int exp);


int main()
{
	printf("Enter your postfix equation: ");
	scanf("%s", s);
	
	eval(s);
	
	printf("Answer: %d", stack[top]);
}

void eval(char s[])
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		
		if (isdigit(s[i]))
		{
			push(s[i] - 48);
		}
		
		else if (s[i] == '+')
	        {
	            int temp = stack[top];
	            pop();
	            
	            stack[top] = stack[top] + temp;
	        }
	        
	        else if (s[i] == '-')
	        {
	            int temp = stack[top];
	            pop();
	            
	            stack[top] = stack[top]- temp;
	        }
	        
	        else if (s[i] == '*')
	        {
	            int temp = stack[top];
	            pop();
	            
	            stack[top] = stack[top] * temp;
	        }
	        
	        else if (s[i] == '/')
	        {
	            int temp = stack[top];
	            pop();
	            
	            stack[top] = stack[top] / temp;
	        }
	        
	        else if (s[i] == '^')
	        {
	            int temp = stack[top];
	            pop();
	            
	            stack[top] = power(stack[top], temp);
	        }
	        
	        else if (s[i] == '%')
	        {
	            int temp = stack[top];
	            pop();
	            
	            stack[top] = stack[top] % temp;
	        }
	}
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
		top--;
		return;
	}

	printf("The stack is empty, cannot delete anything.");
	return;
}

int power(int base, int exp)
{
	int prod = 1;
	for (int z = 0; z < exp; z++)
	{
		prod *= base;
	}
	
	return prod;
}
