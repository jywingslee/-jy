//
//  01.c
//  
//
//  Created by 유저 on 2016. 10. 16..
//
//

#include <stdio.h>

#define max(x, y) ((x) > (y) ? (x):(y))
#define min(x, y) ((x) < (y) ? (x):(y))

int min_v2(int x, int y)
{
    if(x < y)
        return x;
    return y;
}

int max_v2(int x, int y)
{
    if(x > y)
        return x;
    return y;
}


int max_v3(int x, int y, int z)
{
    if(x < y)
    {
        if(z < y)
            return y;
        return z;
    }
    
    if(z < x)
        return x;
    
    return z;
}

int max_v4(int x, int y, int z)
{
    int ans = max(x,y);
    ans = max(ans, z);
    return ans;
}

int max_arr(int length, int arr[])
{
    int i;
    int max = arr[0];
    
    for(i=1;  i<length; i++)
    {
        if(max < arr[i]) max = arr[i];
    }
    
    return max;
}

//설명) 아래 함수는 문제가 없는 재귀 함수이다.
//그런데 max() 코드가 0-3의 매크로 함수이고,
//인자 배열이 단조감소하는 수열이라면 문제가 생긴다.
//예를 들어 배열 a[]가 [1000, 999, ... 1] 이면
//max_arr2(a, 1000)은 매우 오래 걸린다.

//생각) max 매크로 함수에 따라서 코드는 아래처럼 실행될 것이다.
//return (arr[arr_len-1]>max_arr2(arr, arr_len-1):(arr[arr_len-1])?(max_arr2(arr, arr_len-1)))
//비교 하는 문에서 재귀 함수 한번
//실제 값을 구하는 데에서 재귀 함수 한번
//두 번 일을 하는 거는 아닐까??
//이거랑 실제로 각각 각각 원소를 비교하는 방식이기에
//오래 걸릴 것 같다.

int max_arr2(int arr[], int arr_len)
{
    if(arr_len == 1)
        return arr[0];
    else
        return max(arr[arr_len-1], max_arr2(arr, arr_len-1));
}


int main(int argc, const char * argv[]) {
    int len = 3;
    int arr[3] = {4,1,7};
    //printf("%d ", max_arr2(arr, len));
    
    int answer = max_v3(arr[0], arr[1], arr[2]);
    printf("answer = %d \n", answer);
    return 0;
}
