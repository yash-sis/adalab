#include <stdio.h>

int indegree[20], a[20][20], n, s[20];

void topology() {
    int count = 0;

    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        s[i] = 0;
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (a[j][i] == 1) 
                indegree[i]++;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && s[i] == 0) {
                if (count == 0) 
                    printf("The topological ordering of the vertices is:\n");
                
                printf("%d ", i+1);
                
                s[i] = 1;
                count++;
                found = 1;

                for (int j = 0; j < n; j++) 
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
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    topology();
    
    return 0;
}

/*
Enter the number of nodes: 5
Enter the adjacency matrix:
0 1 1 0 0
0 0 0 1 0
0 0 0 0 1
1 0 0 0 0
0 0 0 1 0

Topological ordering is not possible. The given graph is cyclic.

Enter the number of nodes: 5
Enter the adjacency matrix:
0 1 1 0 0
0 0 1 1 0
0 0 0 1 0
0 0 0 0 0
0 0 1 1 0

The topological ordering of the vertices is:
1 2 5 3 4
*/
