#include <stdio.h>

void floyd(int a[20][20], int n) {
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];

    printf("\nThe resultant shortest path matrix is:\n");
    for (int i = 0; i < n; i++, printf("\n")) 
        for (int j = 0; j < n; j++) 
                printf("%4d", a[i][j]);
}

int main() {
    int a[20][20], n;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            scanf("%d", &a[i][j]);

    floyd(a, n);

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
*/
