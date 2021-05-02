#include <stdio.h>
int front =-1, rear =-1;

void function( int graph[][7], int visited[], int queue[], int current, int vertex);

int main () {
    
    int vertex = 7, i=0, j=0, current, visited[20] = {0}, queue[30];
    
    int graph[20][20];

    printf("\nEnter number of vertex:\t");
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
    
    printf("\nSelected starting node:\t 0\n");

    printf("\nBFS Traversal:\t %d ", i);     // 1st selected node  
    queue[++rear] = i;  front = 0;      //enqueue
    visited[i] = 1;     //mark that node as visited

    while( front <= rear) {   // while queue is not empty

        current = queue[front++]; // dequeue

        function(graph, visited, queue, current, vertex);
    }
    return 0;
}
void function( int graph[][7], int visited[], int queue[], int current, int vertex){
    
    for(int j=0; j < vertex; j++) {

        if ( graph[current][j] == 1 && visited[j] == 0) {       //if node not visited
            printf("%d ", j);
            visited[j] = 1;
            queue[++rear] = j ;
        }
    }
}