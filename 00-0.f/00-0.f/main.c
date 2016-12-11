//
//  main.c
//  00-0.f
//
//  Created by 유저 on 2016. 10. 29..
//  Copyright (c) 2016년 유저. All rights reserved.
//

#include <stdio.h>

#define N 10

int main(int argc, const char * argv[]) {
    
    int i, j, k, x = 0;
    
    for(i=0; i<N; i++)
    {
        for(j=i; j<N; j++)
        {
            for(k=j; k<N; k++)
            {
                printf("%d %d %d \n", i, j, k);
                x++;
            }
        }
    }
    
    printf("%d\n", x);
    
    return 0;
}
