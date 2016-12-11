#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define H 3 // 사다리 길이
#define W 3 // 사람 수

int map[H][W] = {
    {1,1,0},
    {0,0,0},
    {0,1,1}
};
void drawMap()
{
    printf("사다리 정보를 입력하세요(x는 입력 완료).\n");
    int x, y;
    
    scanf("%d %d", &x, &y);
    while(x>=1 && x<=H && y>=1 && y<=W)
    {
        map[x-1][y-1] = 1;
        map[x-1][y] = 1;
        
        scanf("%d %d", &x, &y);
        printf("%d %d\n",x, y);
    }
}

int gameStart(int start_people)
{
    int i;
    start_people--;
    for(i=0; i<H; i++)
    {
        if(map[i][start_people] == 0) continue;
        //사다리가 없으면 그냥 아래로 내려갑니다.
        
        else {
            if(start_people+1 <=W && map[i][start_people+1] == 1)
            {
                //사다리가 오른쪽에 있는 경우 오른쪽으로 이동합니다.
                start_people++;
            }
            else if(start_people-1 >=0 && map[i][start_people-1] == 1)
            {
                //사다리가 왼쪽에 있는 경우 왼쪽으로 이동합니다.
                start_people--;
            }
        }
    }
    return start_people+1;
}


int main(int argc, const char * argv[]) {
    
    //drawMap();
    
    // for simple testcase;
    //   1 2 3
    // 1 o o x
    // 2 x x x
    // 3 x o o
    // o -> 다리가 있는 경우
    // x -> 다리가 없는 경우
    int x = 'x';
    printf("%d %d ", x, 'x');
    
    int start, result;
    printf("사다리 게임을 시작할 출발 지점을 입력하세요 (x는 입력 완료)\n");
    scanf("%d", &start);
    
    while( itoa(start) != 'x')
    {
        result = gameStart(start);
        printf("> %d\n", result);
        
        scanf("%d", &start);
    }
    
    return 0;
}
