#include <stdio.h>
#include <time.h>

int w[20], subset[20], n, m;

void sumOfSub(int s, int k, int r) {
    subset[k] = 1;
    
    if (s + w[k] == m) {
        for (int i = 1; i <= n; i++) 
            printf("%d\t", subset[i]);
        printf("\n");
    } else {
        if (s + w[k] + w[k + 1] <= m)
            sumOfSub(s + w[k], k + 1, r - w[k]);
        
        if (s + r - w[k] >= m && s + w[k + 1] <= m) {
            subset[k] = 0;
            sumOfSub(s, k + 1, r - w[k]);
        }
    }
}

int main() {
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the set elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
        subset[i] = 0;
    }

    printf("Enter the maximum subset value: ");
    scanf("%d", &m);

    printf("Solution vectors:\n");
    clock_t start = clock();
    sumOfSub(0, 1, sum);
    clock_t end = clock();

    printf("Time taken: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Enter the number of elements: 5
Enter the set elements: 1 2 5 6 8
Enter the maximum subset value: 9
Solution vectors:
1       1       0       1       0
1       0       0       0       1
Time taken: 0.001000 s
*/
