#include <stdio.h>
#define INF 999

int prim(int a[20][20], int n, int s) {
    int ver[20], d[20], v[20] = {0}, sum = 0, u;

    for (int i = 1; i <= n; i++) {
        ver[i] = s;
        d[i] = a[s][i];
    }
    
    v[s] = 1;

    printf("\nEdges of spanning tree are :");
    for (int i = 1; i < n; i++) {
        int min = INF;
        
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
            if (v[j] == 0 && a[u][j] < d[j]) {
                d[j] = a[u][j];
                ver[j] = u;
            }
        }
    }
    
    return sum;
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
    
    printf("\n\nCost of spanning tree is = %d\n", prim(a, n, s));
    
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

Enter the source node:1

Edges of spanning tree are :
1 -> 3
1 -> 2
3 -> 4
4 -> 6
6 -> 5

Cost of spanning tree is = 11
*/

