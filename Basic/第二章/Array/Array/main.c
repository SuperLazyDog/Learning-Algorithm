//
//  main.c
//  Array
//
//  Created by 徐伟达 on 2017/5/9.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
// 数组的使用
void useArray();
int testFunc(int a);
// 随机数的生成
void createRandomTest();

int main(int argc, const char * argv[]) {
    //--------------------------------------------------------------------------
    //                               数组的使用
    //--------------------------------------------------------------------------
    //useArray();
    //--------------------------------------------------------------------------
    //                              随机数的生成
    //--------------------------------------------------------------------------
    createRandomTest();
    return 0;
}
//-------------------------------------------------------------------------------------------
//                                         函数
//-------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------
//                               数组的使用
//--------------------------------------------------------------------------
void useArray() {
    int a[N];
    int i;
    for(i = 0; i < N; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    printf("数组元素的值：\n");
    for(i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("a Data Length: %lu\na[0] Data Length: %lu\n", sizeof(a), sizeof(a[0]));
    printf("Array Length: %lu\n", sizeof(a)/sizeof(a[0]));
    puts("over");
    i = 1;
    printf("testFunc: %d\n",testFunc(i));
    printf("i: %d\n", i);
    

}


int testFunc(int a) {
    a++;
    return a;
}

//--------------------------------------------------------------------------
//                              随机数的生成
//--------------------------------------------------------------------------
void createRandomTest() {
    int i;
    i = 0;
    const unsigned seed = (unsigned int)time(NULL);
    srand(seed);
    for(i = 0; i < 30; i++){
        printf("%2d回: %d\n", i+1, rand()%10);
    }
}
