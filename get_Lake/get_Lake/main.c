#include <stdio.h>

#define MAX 100
int W, H;
char map[MAX][MAX];
int lake;

void dfs(int y, int x)
{
    map[y][x] = '.';
    
    if(y-1>=0 && map[y-1][x]=='L')
    {
        dfs(y-1, x);
    }
    if(y+1<H && map[y+1][x]=='L')
    {
        dfs(y+1, x);
    }
    if(x-1>=0 && map[y][x-1]=='L')
    {
        dfs(y, x-1);
    }
    if(x+1<W && map[y][x+1]=='L')
    {
        dfs(y, x+1);
    }
    if(y-1>=0 && x-1>=0 && map[y-1][x-1]=='L')
    {
        dfs(y-1,x-1);
    }if(y+1<H && x+1<W && map[y+1][x+1]=='L')
    {
        dfs(y+1,x+1);
    }
    if(y-1>=0 && x+1<W && map[y-1][x+1]=='L')
    {
        dfs(y-1,x+1);
    }if(y+1<H && x-1>=0 && map[y+1][x-1]=='L')
    {
        dfs(y+1,x-1);
    }
}

int main(int argc, const char * argv[]) {
    freopen("/Users/user/input.txt", "r", stdin);
    
    scanf("%d %d ", &W, &H);
    printf("%d %d \n", W, H);
    
    int i, j;
    for(i=0; i<H; i++)
    {
        for(j=0; j<W; j++)
        {
            scanf("%c ", &map[i][j]);
        }
    }
    
    for(i=0; i<H; i++)
    {
        for(j=0; j<W; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    
    for(j=0; j<H; j++)
    {
        for(i=0; i<W; i++)
        {
            if(map[j][i] == 'L'){
                dfs(j, i);
                lake++;
            }
        }
    }
    printf("%d", lake);
    
    return 0;
}
