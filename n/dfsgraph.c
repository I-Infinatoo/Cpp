#include<stdio.h>
int top = -1;

void function (int graph[][20], int visited[], int stack[], int current, int vertex);
int main () {
    
    int graph[20][20], visited[20] = {0}, stack[20], i =0, j=0, current, vertex;

    printf("\nEnter number of Vertex:\t");
    scanf("%d", &vertex); 

    printf("\nEnter Adjecency Matrix:\n");
    for(i =0; i< vertex; i++) {
        for( j=0; j< vertex; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEntered Matrix:\n");
    for(i=0;i<vertex; i++){
        for(j=0;j<vertex;j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nSelect a starting node:(0 - %d):\t", vertex-1 );
    scanf("%d", &i);    //to start from that row
    
    printf("\nSelected starting node:\t %d\n", i);

    printf("\nDFS Traversal:\t");

    stack[++top] = i;   //push to satck

    while( top>=0 ) {
        
        current = stack[top--];
        printf(" %d", current );

        visited[current] = 1;
        function(graph, visited, stack, current, vertex);
    }

    return 0;
}

void function (int graph[][20], int visited[], int stack[], int current, int vertex) {
    
    for (int j =0; j < vertex; j++) {
        
        if ( graph[current][j] == 1 && visited[j] == 0) {  //if not visited
            stack[++top] = j;
        }
    }
}