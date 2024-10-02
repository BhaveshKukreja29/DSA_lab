#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int k[MAX], s, n, ind;
int h[MAX];

void calc_h(int key);
void insert();
void display();

int main()
{
    int opt = -1;

    do {
        printf("Enter size of hash table (max %d): ", MAX);
        scanf("%d", &s);

        if (s > MAX)
        {
            printf("Error: Hash table size cannot exceed %d. Please try again.\n", MAX);
        }
    } while (s > MAX);

    while (opt != 3)
    {
        printf("\nMenu:\n");
        printf("1. Insert keys\n");
        printf("2. Display hash table\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter number of keys to insert (max %d): ", MAX);
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

            for (int i = 0; i < s; i++)
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
            printf("Incorrect choice. Try again.\n");
        }
    }

    return 0;
}

void calc_h(int key)
{
    ind = key % s;
}

void insert()
{
    int i;

    for (i = 0; i < n; i++)
    {
        calc_h(k[i]);

        if (h[ind] != -1)
        {
            printf("Collision for key %d at ind: ", k[i]);

            while (h[ind] != -1)
            {
                printf("%d ", ind);
                ind = (ind + 1) % s;
            }
            printf("\n");
        }

        h[ind] = k[i];
        printf("Inserted %d at index %d\n", k[i], ind);
    }
}

void display()
{
    int i;

    printf("\nCurrent Hash Table:\n");

    for (i = 0; i < s; i++)
    {
        printf("At index %d \t value = %d", i, h[i]);
        if (h[i] == -1) printf("(empty)\n");
        else printf("\n");
    }

    printf("\n");
}
