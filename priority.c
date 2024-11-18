#include <stdio.h>

void main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], priority[n], waiting_time[n], turnaround_time[n];
    int total_wt = 0, total_tat = 0;

    // Input burst time and priority for each process
    printf("Enter burst times and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    // Sort processes by priority (smaller priority number means higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                // Swap burst times
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Swap priorities
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }

    // Calculate waiting time for each process
    waiting_time[0] = 0;  // First process has no waiting time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];  // Waiting time = previous burst time + previous waiting time
    }

    // Calculate turnaround times for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];  // Turnaround time = burst time + waiting time
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    // Output results
    printf("\nPROCESS\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    // Display averages
    printf("\nAvg Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAvg Turnaround Time = %.2f", (float)total_tat / n);
}
