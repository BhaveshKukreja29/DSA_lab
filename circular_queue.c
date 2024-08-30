#include <stdio.h>

#define max 10

int front = -1;
int rear = -1;
int queue[max];


int isEmpty();
int isFull();
void enq(int n);
void deq();
void frontt();
void display();


int main()
{
	int ch;

	do{
		printf("Enter 1 to enqueue. \nEnter 2 to dequeue.\nEnter 3 to Front.\n");
		printf("Enter 4 to check if empty. \nEnter 5 to check if full.\nEnter 6 to display.\nEnter 7 to exit.\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				int num1;
				int n;
				
				printf("Enter the number of elements to enqueue: ");
				scanf("%d", &num1);
				
				if (front == 0 && num1 > (max - rear - 1))
				{
					printf("\nCannot enqueue %d because not enough space, try %d instead.\n\n", num1, max - rear - 1);
					break;
				}
				
				else if (front != 0 && rear != max - 1 && num1 > ( front + (max - 1 - rear) ))
				{
					printf("\nCannot enqueue %d because not enough space, try %d instead.\n\n", num1, max - rear - 1);
					break;
				}
				
				else if (front != 0 && rear == max - 1 && num1 > front)
				{
					printf("\nCannot enqueue %d because not enough space, try %d instead.\n\n", num1, max - rear - 1);
					break;
				}
				
				for (int i = 0; i < num1; i++)
				{
					printf("Enter the element %d: ", i + 1);
					scanf("%d", &n);

					enq(n);
				}
				
				display();
				break;

			case 2:
				int num2;
				
				printf("Enter the number of elements to dequeue: ");
				scanf("%d", &num2);
				
				if (front == 0 && num2 > rear + 1)
				{
					printf("\nCannot dequeue %d because not elements, try %d instead.\n\n", num2, rear + 1);
					break;
				}
				
				else if (front != 0 && rear > front && num2 > (rear + 1 - front))
				{
					printf("\nCannot dequeue %d because not elements, try %d instead.\n\n", num2, rear + 1);
					break;
				}
				
				else if (front != 0 && rear < front && num2 > (front + 1 - rear))
				{
					printf("\nCannot dequeue %d because not elements, try %d instead.\n\n", num2, rear + 1);
					break;
				}
				
				for (int i = 0; i < num2; i++)
				{
					deq();
				}
				
				display();
				break;

			case 3:
				frontt();
				break;
			case 4:
				int s1 = isEmpty();

				if (s1 == 1)
				{
					printf("Queue is indeed empty.\n\n");
				}

				else
				{
					printf("Queue has some elements. \n\n");
				}

				break;
			case 5:
				int s2 = isFull();

				if (s2 == 1)
				{
					printf("Queue is Full.\n\n");
				}

				else
				{
					printf("Queue has space. \n\n");
				}

				break;
			case 6:
				display();
				
			case 7:
				break;

			default:
				printf("Error, please input an integer from 1 to 7.\n\n");
		}
	}while(ch != 7);
}

int isEmpty()
{
	if (rear == -1)
	{
		return 1;
	}

	return 0;
}

int isFull()
{
	if (rear == max - 1 && front == 0)
	{
		return 1;
	}
	
	else if (front != 0 && rear == front - 1)
	{
		return 1;
	}

	return 0;
}

void enq(int n)
{
	if (isEmpty() == 1 && front == -1)
	{
		front = 0;
		rear = 0;
		queue[front] = n;
		printf("\nSuccesfully enqueued %d.\n\n", n);
	}
	
	else if (isFull() == 0)
	{
		if (rear == max - 1)
		{
			rear = 0;
			queue[rear] = n;
			printf("\nSuccesfully enqueued %d.\n\n", n);
		}
		else
		{
			queue[++rear] = n;
			printf("\nSuccesfully enqueued %d.\n\n", n);
		}
	}

	else
	{
		printf("Error. Queue is full.\n\n");
	}
}

void deq()
{
	
	if (isEmpty() == 0)
	{
		printf("\nThe element deleted was: %d\n\n", queue[front]); 
		
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		
		else if (front == max - 1)
		{
			front = 0;
		}
		
		else
		{
			front++;
		}
		
		return;
	}

	printf("The queue is empty, cannot delete anything.\n\n");
	return;
}


void frontt()
{
	if (isEmpty() == 0)
	{
		printf("\nThe front element currently: %d\n", queue[front]);
		printf("\nThe index is %d.\n\n", front);
		return;
	}
	printf("\nQueue is empty.\n\n");
	return;
}


void display()
{
	if (isEmpty() == 0)
	{
		printf("\n\nThis how queue currently is starting from front.\n\n");
		
		if (rear < front)
		{
			for (int i = front; i <= max - 1; i++)
			{
				printf("%d ", queue[i]);
			}
			
			for (int i = 0; i <= rear; i++)
			{
				printf("%d ", queue[i]);
			}
		}
		
		else if (rear > front)
		{
			for (int i = front; i <= rear; i++)
			{
				printf("%d ", queue[i]);
			}
		}
		
		printf("\nThe front element currently: %d\n", queue[front]);
		printf("\nThe index is %d.\n", front);
		
		printf("\nThe rear element currently: %d\n", queue[rear]);
		printf("\nThe index is %d.\n\n", rear);
	}
	
	
	
	else printf("The queue is empty.\n\n");

	return;
}
