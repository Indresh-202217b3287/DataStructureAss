#include <stdio.h>
#include <conio.h>
#define n 5

void main() {
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1;

    // clrscr(); // Uncomment this if your compiler supports clrscr()
    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");
    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (rear == n)
                    printf("\n Queue is Full");
                else {
                    printf("\n Enter no %d: ", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:
                if (front == rear) {
                    printf("\n Queue is Empty");
                } else {
                    printf("\n Deleted Element is %d", queue[front++]);
                    // Adjust rear and front if all elements are deleted
                    if (front == rear) {
                        front = 0;
                        rear = 0;
                    }
                }
                break;
            case 3:
                printf("\n Queue Elements are:\n ");
                if (front == rear) {
                    printf("\n Queue is Empty");
                } else {
                    for (i = front; i < rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                ch = 0; // Exit the loop
                break;
            default:
                printf("Wrong Choice: please see the options");
        }
    }
    getch();
}
