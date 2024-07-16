#include <stdio.h>
#include <time.h>

void warshall(int n, int a[20][20], int p[20][20]) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            p[i][j] = a[i][j];
    
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (p[i][k] && p[k][j])
                    p[i][j] = 1;
}

int main() {
    int a[20][20], p[20][20], n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    clock_t start = clock();
    warshall(n, a, p);
    clock_t end = clock();

    printf("The transitive closure is:\n");
    for (int i = 0; i < n; i++, printf("\n")) 
        for (int j = 0; j < n; j++)
            printf("%d\t", p[i][j]);

    printf("\nTime taken: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

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

Time taken: 0.000000 s
*/
