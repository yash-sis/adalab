#include <stdio.h>

int set[20], subset[20], n, max;

void sumOfSub(int s, int k, int r) {
    subset[k] = 1;
    
    if (s + set[k] == max) {
        for (int i = 1; i <= n; i++) 
            printf("%d\t", subset[i]);
        printf("\n");
    } else {
        if (s + set[k] + set[k + 1] <= max)
            sumOfSub(s + set[k], k + 1, r - set[k]);
        
        if (s + r - set[k] >= max && s + set[k + 1] <= max) {
            subset[k] = 0;
            sumOfSub(s, k + 1, r - set[k]);
        }
    }
}

int main() {
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the set elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &set[i]);
        sum += set[i];
        subset[i] = 0;
    }

    printf("Enter the maximum subset value: ");
    scanf("%d", &max);

    printf("Solution vectors:\n");
    sumOfSub(0, 1, sum);

    return 0;
}

/*
Enter the number of elements: 5
Enter the set elements: 1 2 5 6 8
Enter the maximum subset value: 9
Solution vectors:
1       1       0       1       0
1       0       0       0       1
*/
