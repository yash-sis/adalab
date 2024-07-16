#include <stdio.h>

int indegree[10], flag[10], n, a[10][10];

void topology() {
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        flag[i] = 0;
    }

    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            if (a[j][i] == 1) 
                indegree[i]++;

    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (indegree[i] == 0 && flag[i] == 0) {
                if (count == 0) 
                    printf("The topological ordering of the vertices is:\n");
                
                printf("%d ", i+1);
                
                flag[i] = 1;
                count++;
                found = 1;

                for (j = 0; j < n; j++) 
                    if (a[i][j] == 1) 
                        indegree[j]--;
                        
                break;
            }
        }

        if (!found) {
            if (count == 0) 
                printf("\nTopological ordering is not possible. The given graph is cyclic.\n");
            
            return;
        }
    }
    
    printf("\n");
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    topology();
    
    return 0;
}
