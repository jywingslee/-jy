#include <stdio.h>
#define N 1000

int bank_time[N];
int bank_order[N];

int P, answer;

void print()
{
    int i;
    for(i=0; i<P; i++)
    {
        printf("%d ", bank_time[i]);
    }
    printf("\n");
}

void get_time()
{
    int i, j, min, swap;
    for(i=0; i<P-1; i++)
    {
        min = bank_time[i];
        swap = i;
        for(j=i+1; j<P; j++)
        {
            //if(i == j)continue;
            if(min > bank_time[j]){
              min = bank_time[j];
              swap = j;
            }
        }
        
        //printf("min = %d\n", min);
        
        int tmp = bank_time[swap];
        bank_time[swap] = bank_time[i];
        bank_time[i] = tmp;
        
        //print();
        //bank_time[min], j //swap
        
        //bank_order[i] = min;
    }
}

int get_total()
{
    int total = 0;
    int i, j;
    int sum = 0;
    
    for(i=0; i<P; i++)
    {
        sum = 0;
        for(j=0; j<=i; j++)
        {
            sum+=bank_time[j];
        }
        total += sum;
    }
    
    return total;
}
int main(int argc, const char * argv[]) {
    
    scanf("%d", &P);
    
    int i;
    for(i=0; i<P; i++)
    {
        scanf("%d", &bank_time[i]);
    }
    
    get_time();
    
    answer = get_total();
    
    printf("%d\n", answer);
    
    return 0;
}
