#include <stdio.h>

struct Knap
{
    int profit, weight;
    double ratio;
};

const int n = 7;
int w = 15;

int p[] = {10, 5, 15, 7, 6, 18, 3};
int wt[] = {2, 3, 5, 7, 1, 4, 1};

struct Knap arr[n] = {0};

void initialise()
{
    for (int i = 0; i < n; i++)
    {
        arr[i].profit = p[i];
        arr[i].weight = wt[i];
        arr[i].ratio = 1.0 * p[i] / wt[i];
    }
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d) ", arr[i].profit, arr[i].weight);
    }
}

void sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].ratio > arr[j + 1].ratio)
            {
                struct Knap temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void fractKnapsack()
{
    double x[n] = {0, 0};
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight > w)
        {
            x[i] = 1.0 * w / arr[i].weight;
            ans += x[i] * arr[i].profit;
            break;
        }
        else
        {
            x[i] = 1.0;
            ans += x[i] * arr[i].profit;
            w -= arr[i].weight;
        }
    }
    printf("Total profit: %.21f\n", ans);
}

int main(void)
{
    initialise();
    display();
    sort();
    printf("\n");
    display();
    fractKnapsack();

    return 0;
}