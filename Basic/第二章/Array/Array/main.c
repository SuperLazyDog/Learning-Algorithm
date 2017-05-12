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
#define ARRAY_SIZE 15
enum whether {
    true = 1,
    false = 0
};
typedef enum whether bool;
// 数组的使用
void useArray();
int testFunc(int a);
// 随机数的生成
void createRandomTest();
//逆序数组
bool getRandomArray(int howMany, int *arrayTemp);
bool reverseArray(int *array);
bool showArray(int *array);

int main(int argc, const char * argv[]) {
    //--------------------------------------------------------------------------
    //                               数组的使用
    //--------------------------------------------------------------------------
    //useArray();
    //--------------------------------------------------------------------------
    //                              随机数的生成
    //--------------------------------------------------------------------------
    //createRandomTest();
    //--------------------------------------------------------------------------
    //                               逆序数组
    //--------------------------------------------------------------------------
    //getRandomArray(14);
    //int temp[128] = {1,2,3,4,5};
    //int *array = temp;//getRandomArray(15);
    int *array = (int *)malloc(ARRAY_SIZE*sizeof(int));
    getRandomArray(ARRAY_SIZE, array);
    showArray(array);
    reverseArray(array);
    showArray(array);
    printf("%d %d %d\n", *(array+3), *array, *(array+1));
    free(array);
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
//--------------------------------------------------------------------------
//                               逆序数组
//--------------------------------------------------------------------------
//获取随机的整数数组
bool getRandomArray(const int howMany, int *arrayTemp) {
    int j = 0;
    const unsigned seed = (unsigned int)time(NULL);
    srand(seed);
    for(j=0; j<howMany; j++) {
        *arrayTemp = j;//rand();
        arrayTemp++;
    }
    arrayTemp -= ARRAY_SIZE;
    return true;
}
//把数组倒序
bool reverseArray(int *array) {
    int i;
    for(i=0; i<ARRAY_SIZE/2; i++) {
        int temp = array[i];
        array[i] = array[ARRAY_SIZE-1-i];
        array[ARRAY_SIZE-1-i] = temp;
    }
    return true;
}
//输出数组
bool showArray(int *array) {
    int i = 0;
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("第%2d个: %d\n", i, *array);
        array++;
    }
    array -= ARRAY_SIZE;
    return true;
}
