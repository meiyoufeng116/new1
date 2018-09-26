//
//  main.c
//  动态数组--3元组
//
//  Created by Mac on 2018/9/11.
//  Copyright © 2018年 Mac. All rights reserved.
//
#define SIZE 100 //初始分配量
#define LISTIINCREMENT 10//增量
#define overflew -2
#include <stdio.h>
#include <stdlib.h>
typedef  int dong;
int InitTriplet(dong *i)
{
    i=(int*)malloc(3*sizeof(int));
    if (!i) exit(overflew);
    return 0;
}
int Max(int a[])
{
    int i,j,t;
    for(j=0;j<3;j++)
        for(i=0;i<3-1-j;i++)
            if(a[i]>a[i+1]) /* 由小到大,由大到小时改为< */
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
    return a[2];
}
int DestroyTriplet(int a[])
{
    free(a);
    a=NULL;
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int *a = NULL,b,i;
    InitTriplet(a);
    for (i=0; i<3; i++) {
        scanf("%d",&a[i]);
    }
    b=Max(a);
    printf("%d",b);
    
}
