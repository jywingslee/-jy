#include <stdio.h>

#define M 300
#define N 8

int moving[N][2] = {
    //
    //{y,x}
    {-1,-2},
    {-2,-1},
    {-2, 1},
    {-1, 2},
    {1,  2},
    {2,  1},
    {2, -1},
    {1, -2}
};

int L;

int start_x, start_y;
int dest_x , dest_y;

int visit[M][M];

int is_inboundary(int y, int x)
{
    if(y>=0 && y<L && x>=0 && x<L) return 1;
    return 0;
}

int is_visit(int y, int x)
{
    if(is_inboundary(y,x))
    {
        if(visit[y][x] == 0)
        {
            visit[y][x] = 1;
            return 0;
        }
        return 1;
    }
    return 1;
}
int v;
int move_x;
int move_y;
int result;
void printmap()
{
    int i, j;
    for(i=0; i<L; i++)
    {
        for(j=0; j<L; j++)
        {
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
}
void search(int y, int x, int depth)
{
    printmap();

    if(y == dest_y && x == dest_x){
        printf("!!! %d \n", depth);
        result = depth;
        return;
    }
    
    visit[y][x] = 1;
    for(v=0; v<N; v++)
    {
        move_x = x+moving[v][1];
        move_y = y+moving[v][0];
        
        if(is_inboundary(move_y, move_x))
        {
            if(visit[move_y][move_x] == 0)
            {
                search(move_y, move_x, depth+1);
                visit[move_y][move_x] = 0;
            }
        }
    }
    //return 0;
    //return depth;
}



int main(int argc, const char * argv[]) {
    
    //freopen("input.txt", "r", stdin);
    int t,test_case;
    scanf("%d", &test_case);
    
    for(t=0; t<test_case; t++)
    {
        scanf("%d", &L);
        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &dest_x, &dest_y);
        
        search(start_y, start_x, 0);
        printf("%d\n", result);
    }
    
    return 0;
}
