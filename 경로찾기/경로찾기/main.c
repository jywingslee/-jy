#include <stdio.h>

#define MAX 100
int graph[MAX][MAX];
int map[MAX][MAX];
int visit[MAX][MAX];
int L;
int i;

void dfs(int v)
{
    map[v][v] = 1;
    
    for(i=0; i<L; i++)
    {
        if(i == v) continue;
        else if(graph[v][i] == 1) map[v][i] = 1;
        else {
            for(j=0; j<L; j++)
            {
                if(v!=j)continue;
                if(map[j][i] == 1)
            }
        }
    }
    
    
}

void printmap()
{
    
}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &L);
    
    int i, j;
    for(i=0; i<L; i++)
    {
        for(j=0; j<L; j++)
        {
            scanf("%d", graph[i][j]);
        }
    }
    
    dfs(0);
    
    printmap();
    
    
    return 0;
}
