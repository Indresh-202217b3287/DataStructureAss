#include <stdio.h>

// Remove conio.h as it's not a standard library
// Instead, use standard C libraries

int main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;
    
    // Initializing arrays
    for (i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }
    
    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Input the burst times
    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    // Input the arrival times
    printf("\nEnter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Calculate gantt chart times
    g[0] = 0;
    for (i = 0; i < n; i++) {
        g[i + 1] = g[i] + b[i];
    }
    
    // Calculate waiting and turnaround times
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt += w[i];
        att += t[i];
    }
    
    // Calculate average waiting and turnaround times
    awt = awt / n;
    att = att / n;
    
    // Display process, waiting time, and turnaround time
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }
    
    // Display average waiting and turnaround times
    printf("The average waiting time is %f\n", awt);
    printf("The average turnaround time is %f\n", att);
    
    return 0;
}