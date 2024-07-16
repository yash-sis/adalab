#include <stdio.h>

int weight[20], value[20], b[20], F[20][20];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack01(int n, int W) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) 
                F[i][w] = 0;
            else if (weight[i-1] <= w) 
                F[i][w] = max(F[i-1][w], value[i-1] + F[i-1][w - weight[i-1]]);
            else 
                F[i][w] = F[i-1][w];
        }
    }

    printf("\nMaximum profit: %d\n", F[n][W]);
}

int main() {
    int n, W;

    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &n, &W);

    printf("Enter weights and values of the items:\n");
    for (int i = 0; i < n; i++) 
        scanf("%d %d", &weight[i], &value[i]);
    
    knapsack01(n, W);

    return 0;
}

/*
Enter number of items and knapsack capacity: 4 5
Enter weights and values of the items:
2 12
1 10
3 20
2 15
Maximum profit: 37
*/
