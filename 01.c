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

//아래 함수는 문제가 없는 재귀 함수이다.

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
