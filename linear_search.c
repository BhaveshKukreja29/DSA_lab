#include <stdio.h>
#include <stdlib.h>

int linearsearch(int *arr, int n, int s);
int ind[10];

int main()
{
		int n;
		int s;
		printf("Enter the size of array: ");
		scanf("%d", &n);
		
		int *arr = (int *)malloc(sizeof(int)*n);
		
		for (int i = 0; i < n; i++)
		{
			printf("Enter the no. %d element: ", i + 1);
			scanf("%d", &arr[i]);
		}
		
		printf("Enter the number to search: ");
		scanf("%d", &s);
		
		int m = linearsearch(arr, n, s);
		
		if (m == - 1) printf("Not found");
		
		else
		{
			printf("It is present at ");
			for (int i = 0; i < m; i++)
			{
				printf("%d ", ind[i]);
			}
			printf("indices.");
		}
		free(arr);
}

int linearsearch(int *arr, int n, int s)
{
	int val = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
			if (s == arr[i])
			{
					ind[count] = i;
					count++;
					val = 1;
			}
	}	
	
	if (val == 1) return count;
	else return -1;
}
