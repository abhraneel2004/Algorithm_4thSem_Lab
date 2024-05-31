#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    char id; // Job ID
    int deadline; // Deadline of the job
    int profit; // Profit of the job
};

// Function to sort the jobs based on profit in descending order
void sortByProfit(struct Job arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].profit < arr[j + 1].profit) {
                struct Job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the maximum deadline
int findMaxDeadline(struct Job arr[], int n) {
    int maxDeadline = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
    }
    return maxDeadline;
}

// Function to perform job sequencing
void jobSequencing(struct Job arr[], int n) {
    // Sort the jobs based on profit in descending order
    sortByProfit(arr, n);

    // Find the maximum deadline
    int maxDeadline = findMaxDeadline(arr, n);

    // Initialize the result array
    char result[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = '-';
    }

    // Perform job sequencing
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (result[j] == '-') {
                result[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    // Print the sequence and total profit
    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != '-') {
            printf("%c ", result[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    // Example usage
    struct Job arr[] = {
        {'a', 4, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 30}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given Jobs:\n");
    printf("ID   Deadline   Profit\n");
    for (int i = 0; i < n; i++) {
        printf("%c       %d           %d\n", arr[i].id, arr[i].deadline, arr[i].profit);
    }
    printf("\n");

    jobSequencing(arr, n);

    return 0;
}
