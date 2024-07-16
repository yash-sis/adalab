#include <stdio.h>
#include <time.h>
#define INF 999

void floyd(int graph[20][20], int n) {
    int dist[20][20];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("\nThe resultant shortest path matrix is:\n");
    for (int i = 0; i < n; i++, printf("\n")) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
    }
}

int main() {
    int graph[20][20], n;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            scanf("%d", &graph[i][j]);

    clock_t start = clock();
    floyd(graph, n);
    clock_t end = clock();

    printf("\nTime taken: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Enter the number of nodes: 4
Enter the cost adjacency matrix:
0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0

The resultant shortest path matrix is:
   0  10   3   4
   2   0   5   6
   7   7   0   1
   6  16   9   0

Time taken: 0.010000 s 
*/