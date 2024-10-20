//. Implement Hashing using array. Demonstrate Linear Probing to handle collision.

#include <stdio.h>

#define MAX 10

int k[MAX], size, ind, n;
int h[MAX];

void hash(int key);
void insert();
void display();

int main()
{
    int c = -1;

    do{
        printf("Enter size of table (max %d): ", MAX);
        scanf("%d", &size);
    }while(size > MAX);

    while (c != 3)
    {
        printf("Enter 1 to insert into table, 2 to display, 3 to exit.");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter number of keys (max %d): ", MAX);
            scanf("%d", &n);

            if (n > MAX)
            {
                printf("Error: Number of keys cannot exceed %d.\n", MAX);
                break;
            }

            printf("Enter keys: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &k[i]);
            }

            for (int i = 0; i < size; i++)
            {
                h[i] = -1;
            }

            insert(); 
            break;
        case 2:
            display();
            break;

        case 3: 
            break;

        default:
            printf("Try again.");
            break;
        }
    }

    return 0;
}

void hash(int key)
{
    ind = key % size;
}

void insert()
{
    int i;
    int j = 0;
    
    for (i = 0; i < n; i++)
    {
        hash(k[i]);

        if (h[ind] != -1)
        {
            printf("Collision at index: ");
            while (h[ind] != -1)
            {
                printf("%d", ind);
                j++;
                hash(k[i] + j*j);
            }
            j = 0;
        }
        h[ind] = k[i];
        printf("Inserted %d at index %d\n", k[i], ind);
    }
}

void display()
{
    int i;

    printf("\nCurrent Hash Table:\n");

    for (i = 0; i < size; i++)
    {
        printf("At index %d \t value = %d", i, h[i]);
        if (h[i] == -1) printf("(empty)\n");
        else printf("\n");
    }

    printf("\n");
}