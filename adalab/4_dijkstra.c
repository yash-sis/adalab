#include <stdio.h>
#define INF 999

void dijkstra(int a[20][20], int n, int s) {
    int p[20], d[20], v[20] = {0}, min, u;

    for (int i = 1; i <= n; i++) {
        p[i] = s;
        d[i] = a[s][i];
    }

    v[s] = 1;
    d[s] = 0;

    for (int i = 1; i < n; i++) {
        min = INF;

        for (int j = 1; j <= n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;

        for (int j = 1; j <= n; j++) {
            if (v[j] == 0 && d[u] + a[u][j] < d[j]) {
                d[j] = d[u] + a[u][j];
                p[j] = u;
            }
        }
    }

    printf("Shortest path costs from vertex %d:\n", s);
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF)
            printf("No path to vertex %d\n", i);
        else
            printf("To %d: %d\n", i, d[i]);
    }

    printf("Shortest group of paths are:\n");
    for (int i = 1; i <= n; i++) {
        if (i != s && d[i] != INF) {
            printf("%d", i);

            int j = p[i];

            while (j != s) {
                printf(" <- %d", j);

                j = p[j];
            }

            printf(" <- %d\n", s);
        }
    }
}

int main() {
    int a[20][20], n, s;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter the source node: ");
    scanf("%d", &s);

    dijkstra(a, n, s);

    return 0;
}

/*
Enter the number of nodes: 5
Enter the cost adjacency matrix:
0 3 999 7 999
999 0 4 2 999
999 4 0 5 6
7 2 5 0 4
999 999 6 4 0

Enter the source node: 1
Shortest path costs from vertex 1:
To 1: 0
To 2: 3
To 3: 7
To 4: 5
To 5: 9
Shortest group of paths are:
2 <- 1
3 <- 2 <- 1
4 <- 2 <- 1
5 <- 4 <- 2 <- 1
*/

