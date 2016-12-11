#include <stdio.h>

#define MAX 5000

int N; //사탕 종류의 수
double M; //상근이가 가지고 있는 돈의 양
int max_Cost; //최대 값

typedef struct _candy{
    int Calrory;
    double Cost;
}_candy;

_candy candy[MAX];

int temp_cost;
int temp_calrory;
int max_calrory;

void make_candy(int v, int flag, int cost, int calrory)
{
    
    if(cost > M) return;
    
    if(calrory > max_calrory) max_calrory = calrory;
    
    //Slected case!
    make_candy(v+1, 1, cost+candy[v].Cost, calrory+candy[v].Calrory);
    
    //Not Selected case!
    make_candy(v+1, 0, cost, calrory);
    
}

int main(int argc, const char * argv[]) {

    scanf("%d %lf", &N, &M);
    
    int i;
    for(i=0; i<N; i++)
    {
        scanf("%d %lf", &candy[i].Calrory, &candy[i].Cost);
    }
    
    make_candy(0, 0, 0, 0);
    
    printf("%d\n", max_calrory);
    
    return 0;
}
