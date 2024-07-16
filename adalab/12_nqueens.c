#include <stdio.h>
#include <stdlib.h>

void printSolution(int n, int x[]) {
    for (int i = 1; i <= n; i++, printf("\n"))
        for (int j = 1; j <= n; j++)
            printf("%c\t", (x[i] == j) ? 'Q' : '-');
}

int isPlaceable(int x[], int k) {
    for (int i = 1; i < k; i++)
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
            return 0;

    return 1;
}

void solveNQueens(int n) {
    int x[20] = {0}, k = 1, count = 0;

    while (k != 0) {
        x[k]++;

        while (x[k] <= n && !isPlaceable(x, k)) x[k]++;

        if (x[k] <= n) {
            if (k == n) {
                printf("Solution %d:\n", ++count);
                printSolution(n, x);
            } else x[++k] = 0;
        } else k--;
    }
}

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    solveNQueens(n);

    return 0;
}

/*
Enter the number of queens: 4
Solution 1:
-       Q       -       -
-       -       -       Q
Q       -       -       -
-       -       Q       -
Solution 2:
-       -       Q       -
Q       -       -       -
-       -       -       Q
-       Q       -       -
*/
