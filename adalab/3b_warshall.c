#include <stdio.h>

void warshall(int a[20][20], int n) {    
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][k] && a[k][j])
                    a[i][j] = 1;

    printf("\nThe transitive closure is:\n");
    for (int i = 0; i < n; i++, printf("\n")) 
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
}

int main() {
    int a[20][20], n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    warshall(a, n);

    return 0;
}

/*
Enter the number of nodes: 4
Enter the adjacency matrix:
0 1 0 0
0 0 0 1 
0 0 0 0 
1 0 1 0

The transitive closure is:
1       1       1       1
1       1       1       1
0       0       0       0
1       1       1       1
*/
