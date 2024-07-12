#include <stdio.h>
#include <stdlib.h>

void sort_arr(int *arr, int n);
void binary_search(int *arr, int n);

int main()
{
		int n;
		printf("Enter the size of Array: ");
		scanf("%d", &n);
		
		int *arr = (int *)malloc(sizeof(int)*n);
		
		for (int i = 0; i < n; i++)
		{
				printf("Enter the %d element: ", i + 1);
				scanf("%d", &arr[i]);
		}
		
		sort_arr(arr, n);
		
		binary_search(arr,n);
}

void sort_arr(int *arr, int n)
{
		for (int i = 0; i < n; i++)
		{
				for (int j = 0; j < n - 1; j++)
				{
					if (arr[j] > arr[j + 1])
					{
							int temp = arr[j];
							arr[j] = arr[j + 1];
							arr[j + 1] = temp;
					}
				}
		}
		
		printf("Sorted array: [ ");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("]");
}

void binary_search(int *arr, int n)
{
	
		int m;
		printf("Enter the number you wish to search: ");
		scanf("%d", &m);
		
		int low = arr[0];
		int mid = arr[((n-1)/2)];
		int high = arr[n-1];
		
		int lowind = 0;
		int midind = (n-1)/2;
		int highind = n - 1;
		
		int val = 1;
		
		while (val != 0)
		{
				if (m > low && m < mid)
				{
					high = mid;
					highind = midind;
					int temp = arr[highind/2];
					mid = temp;
					midind = highind/2;
				}
				
				else if (m < high && m > mid)
				{
					low = mid;
					lowind = midind;
					int temp = arr[lowind/2];
					mid = temp;
					midind = lowind/2;
				}
				
				else if (m == mid)
				{
					printf("It is found at %d index.", midind);
					break;
				}
				else if (m == high)
				{
					printf("It is found at %d index.", highind);
					break;
				}
				else if (m == low)
				{
					printf("It is found at %d index.", lowind);
					break;
				}
				
				else
				{
					val = 0;
					break;
				}
		}
		
		if (val == 0) printf("Not found.");
}
