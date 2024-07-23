#include <stdio.h>
#define INF 999

int p[20], t[20][2];

int find(int v) {
    while (p[v])
        v = p[v];
    
    return v;
}

void union1(int i, int j) {
    p[j] = i;
}

int kruskal(int a[20][20], int n) {
    int sum = 0;

    for (int k = 1; k < n; k++) {
        int min = INF;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i][j] < min) {
                    if (find(i) != find(j)) {
                        min = a[i][j];
                        t[k][0] = i;
                        t[k][1] = j;
                    }
                }
            }
        }

        union1(find(t[k][0]), find(t[k][1]));
        sum += min;
    }
   
    printf("\nEdges of spanning tree are:\n");
    for (int i = 1; i < n; i++) 
        printf("%d -> %d\n", t[i][0], t[i][1]);
    
    return sum;
}

int main() {
    int a[20][20], n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        p[i] = 0;

        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\nCost of spanning tree is = %d\n", kruskal(a, n));
    
    return 0;
}

/*
Enter the number of nodes: 6
Enter the cost adjacency matrix:
999 2 1 999 999 999
2 999 3 5 999 999
1 3 999 3 6 999
999 5 3 999 8 4
999 999 6 8 999 1
999 999 999 4 1 999

Edges of spanning tree are:
1 -> 3
5 -> 6
1 -> 2
3 -> 4
4 -> 6

Cost of spanning tree is = 11
*/
