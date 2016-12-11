#include <stdio.h>

#define MAX 5000
int N, M;

N = 3;
M = 8;

int c[MAX];
int cc[MAX];

int p[MAX];

c[MAX] = {700, 299, 499};
p[MAX] = {7, 3, 5};

int candy = 0;

int calc_calrory()
{
    int i;
    int tot = 0;
    for(i=0; i<N; i++)
    {
        if(cc[i]){
            tot+=c[i];
        }
    }
    return tot;
}
int check_money()
{
    int i;
    int m;
    for(i=0; i<N; i++)
    {
        if(cc[i]) m+=p[i];
    }
    
    if(m<=M) return 1;
    return 0;
}
void max_calrory(int v)
{
    if(v == N-1){
        if(check_money())
        {
            int tot = calc_calrory();
            if(candy < tot) candy = tot; //candy max value update!
        }
        return;
    }
    
    cc[v] = 0;
    max_calrory(v+1);
    
    cc[v] = 1;
    max_calrory(v+1);
}

int main(int argc, const char * argv[]) {

    max_calrory(0);
    
    printf("%d\n", candy);
    
    return 0;
}
