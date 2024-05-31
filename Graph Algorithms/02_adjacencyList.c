#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *arr[10];

void insertAtEnd(int vert, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (arr[vert] == NULL)
    {
        arr[vert] = temp;
        return;
    }
    else
    {
        struct Node *t2 = arr[vert];
        while (t2->next != NULL)
        {
            t2 = t2->next;
        }
        t2->next = temp;

        return;
    }
}

void displayLL(int vert)
{
    struct Node *h = arr[vert];
    if (h == NULL)
        return;
    struct Node *temp = h;
    while (temp)
    {
        printf("%c-> ", 65+(temp->data));
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void)
{
    FILE *fp;
    fp = fopen(".././graphs/abc.txt", "r");
    if (fp == NULL)
    {
        printf("Error in Opening File\n");
        exit(1);
    }

    else
    {
        int n, i, j;
        fscanf(fp, "%d", &n);

        // creating adjacency matrix for graph
        int graph[10][10];

        // Reading adjacency matrix from file
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                fscanf(fp, "%d", &graph[i][j]);
            }
        }


        for (int i = 0; i < 10; i++)
        {
            arr[i] = NULL;
        }
        // creating adjacency list
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] == 1)
                {
                    insertAtEnd(i, j);
                }
            }
        }

        printf("Adjacency List: \n");

        for (i = 0; i < n; i++)
        {
            printf("%c: ", 65+i);
            displayLL(i);
        }
    }
    return 0;
}