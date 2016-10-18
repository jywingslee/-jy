#include <stdio.h>

#define QUEUE_CAPACITY 8 // 큐에 사용되는 배열의 크기

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;
int queue_size = 0;

void enqueue(int n)
{
    if(queue_size == QUEUE_CAPACITY)
    {
        printf("queue full!\n");
        return;
    }
    tail++;
    queue_size++;
    queue[tail] = n;
}

int dequeue()
{
    if(queue_size == 0)
    {
        printf("queue empty!\n");
        return 0;
    }
    queue_size--;
    return queue[head++];
}

//은행에서 대기 번호를 관리하는 프로그램을 작성해보자.
//이 프로그램은 대기번호(자연수)가 입력되면 큐에 저장한다.
//0이 입력되면 큐에서 가장 오래 기다린 대기번호를 꺼내어 출력한다.
//0을 입력했을 때 큐가 비었으면 "queue empty!"를 출력하고
//배열이 가득 차서 더 넣을 수가 없을 때는 "queue full!"을 출력한다.

int main(int argc, const char * argv[]) {
    
    int number, r;
    
    do{
        printf("input number: ");
        scanf("%d", &number);
        
        if(number > 0){
            enqueue(number);
        }
        else if(number == 0){
            r = dequeue();
            printf("[%d]\n", r);
        }
    }while(number >= 0);
    
    return 0;
}
