#include <stdio.h>
#include <time.h>
#define INF 999

int d[20], s[20], w[20][20], p[20], n, v;

int findmin() {
    int min = -1;

    for (int i = 1; i <= n; i++) 
        if (s[i] == 0 && (min == -1 || d[i] < d[min])) 
            min = i;

    return min;
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = INF;
        p[i] = 0;
    }

    d[v] = 0;

    for (int k = 1; k <= n; k++) { 
        int u = findmin();

        s[u] = 1;

        for (int w1 = 1; w1 <= n; w1++) { //w1 is neighbour
            if (w[u][w1] != INF && s[w1] == 0 && d[w1] > d[u] + w[u][w1]) {
                d[w1] = d[u] + w[u][w1];
                p[w1] = u;
            }
        }
    }

    printf("Shortest path costs from vertex %d:\n", v);
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF)
            printf("No path to vertex %d\n", i);
        else
            printf("To %d: %d\n", i, d[i]);
    }

    printf("Shortest group of paths are:\n");
    for (int i = 1; i <= n; i++) {
        if (i != v && d[i] != INF) {
            printf("%d", i);

            int j = p[i];

            while (p[j] != 0) {
                printf(" <- %d", j);
                j = p[j];
            }

            printf(" <- %d\n", v);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            scanf("%d", &w[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &v);

    clock_t start = clock();
    dijkstra();
    clock_t end = clock();

    printf("Time taken: %lf s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Enter the number of vertices: 5
Enter the cost adjacency matrix:
0 3 999 7 999
999 0 4 2 999
999 4 0 5 6
7 2 5 0 4
999 999 6 4 0
Enter the source vertex: 1
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
Time taken: 0.013000 s
*/
