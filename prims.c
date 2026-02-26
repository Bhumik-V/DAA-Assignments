// Maximum Spanning Tree using PRIM's Algorithm
#include<stdio.h>
#include<limits.h>

int main() {
    int V, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int selected[V];
    for(i = 0; i < V; i++)
        selected[i] = 0;

    selected[0] = 1;

    int no_edge = 0;

    printf("Edges in MST:\n");

    while(no_edge < V - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;

        for(i = 0; i < V; i++) {
            if(selected[i]) {
                for(j = 0; j < V; j++) {
                    if(!selected[j] && graph[i][j]) {
                        if(min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);

        selected[y] = 1;
        no_edge++;
    }

    return 0;
}
