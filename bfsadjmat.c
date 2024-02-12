#include <stdio.h>
int v,k;

void printgraph(int adj[v][v]) {
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) 
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

int dtn(int s) {
    k=0;
    k++;
    return k;
}

int main() {
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    int adj[v][v],s,d;
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) 
            adj[i][j]=0;
    }

    while(s!=-1 && d!=-1) {
        printf("Enter the source and destination vertex : ");
        scanf("%d %d", &s, &d);
        adj[s][d] = 1;
        adj[d][s] = 1;
    }
    printgraph(adj);

    return 0;
}

