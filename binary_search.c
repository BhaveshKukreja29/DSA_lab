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
		
		int val = 0;
		
		do
		{
            
            if (m == mid)
			{
				printf("It is found at %d index.", midind);
                val = 1;
				break;
            }

            else if (m == high)
            {
                printf("It is found at %d index.", highind);
                val = 1;
                break;
            }
            else if (m == low)
            {
                printf("It is found at %d index.", lowind);
                val = 1;
                break;
            }

            else if (m < mid)
            {
                high = arr[midind - 1];
                highind = midind - 1;
                midind = (lowind + highind) / 2;
                mid = arr[midind];
            }
            
            else if (m > mid)
            {
                low = arr[midind + 1];
                lowind = midind + 1;
                midind = (lowind + highind) / 2;
                mid = arr[midind];
            }
         }while (lowind < highind);
		
		if (val == 0) printf("Not found.");
}
