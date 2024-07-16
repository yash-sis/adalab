#include <stdio.h>

void knapsackGreedy(int n, float weight[], float profit[], float capacity) {
    float tp = 0, u = capacity, x[20] = {0};

    for (int i = 0; i < n; i++) {
        if (weight[i] > u) {
            x[i] = u / weight[i];
            tp += x[i] * profit[i];
            break;
        } else {
            x[i] = 1;
            tp += profit[i];
            u -= weight[i];
        }
    }

    printf("\nMaximum profit: %.2f\n", tp);
}

int main() {
    int n;
    float weight[20], profit[20], capacity;

    printf("Enter the number of items and knapsack capacity: ");
    scanf("%d %f", &n, &capacity);

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%f %f", &weight[i], &profit[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((profit[i] / weight[i]) < (profit[j] / weight[j])) {
                float temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
                temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
            }
        }
    }

    knapsackGreedy(n, weight, profit, capacity);

    return 0;
}

/*
Enter the number of items and knapsack capacity: 3 20
Enter the weights and values of the items:
15 24
10 15
18 25

Maximum profit: 31.50
*/
