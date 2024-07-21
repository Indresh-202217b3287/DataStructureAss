#include <stdio.h>
#include <conio.h>
#define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0;

void main()
{
    int ch;
    char g = 'y';
    do
    {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display\n 6. Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            insert();
            break;
        case 5:
            display();
            break;
        case 6:
            return;
        default:
            printf(" \n Enter the correct choice:");
        }
        
        printf("\n Do you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');

    getch();
}

void create()
{
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);

    printf("\n Enter the Elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
    int pos;
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0)
    {
        printf("\n Invalid Location::");
    }
    else
    {
        for (int i = pos; i < n - 1; i++)
        {
            b[i] = b[i + 1];
        }
        n--;
        printf("\n The elements after deletion are:");
        display();
    }
}

void search()
{
    int e, found = 0;
    printf("\n Enter the element to be searched: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            printf("Value %d is at position %d\n", e, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Value %d is not in the list\n", e);
    }
}

void insert()
{
    int pos, p;
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos > n || pos < 0 || n >= MAX)
    {
        printf("\n Invalid Location::");
    }
    else
    {
        for (int i = n; i > pos; i--)
        {
            b[i] = b[i - 1];
        }
        printf("\n Enter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
        printf("\n The list after insertion is:\n");
        display();
    }
}

void display()
{
    printf("\n The elements of the list are:");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", b[i]);
    }
    printf("\n");
}
