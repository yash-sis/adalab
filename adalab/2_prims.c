#include <stdio.h>
#define INF 999

int prim(int c[20][20], int n, int s) {
    int ver[20], d[20], v[20] = {0}, sum = 0, min, u;

    for (int i = 1; i <= n; i++) {
        ver[i] = s;
        d[i] = c[s][i];
    }
    
    v[s] = 1;

    printf("\nEdges of spanning tree are :");
    for (int i = 1; i <= n - 1; i++) {
        min = INF;
        
        for (int j = 1; j <= n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        
        v[u] = 1;
        sum += d[u];

        printf("\n%d -> %d", ver[u], u);
        
        for (int j = 1; j <= n; j++) {
            if (v[j] == 0 && c[u][j] < d[j]) {
                d[j] = c[u][j];
                ver[j] = u;
            }
        }
    }
    
    return sum;
}

int main() {
    int c[20][20], res, s, n;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    
    printf("\nEnter the source node: ");
    scanf("%d", &s);
    
    res = prim(c, n, s);
    printf("\n\nCost of spanning tree is = %d\n", res);
    
    return 0;
}

/*
Enter the number of vertices: 6
Enter the cost adjacency matrix:
999 2 1 999 999 999
2 999 3 5 999 999
1 3 999 3 6 999
999 5 3 999 8 4
999 999 6 8 999 1
999 999 999 4 1 999

Enter the source node:1

Edges of spanning tree are :
1 -> 3
1 -> 2
3 -> 4
4 -> 6
6 -> 5

Cost of spanning tree is = 11
*/