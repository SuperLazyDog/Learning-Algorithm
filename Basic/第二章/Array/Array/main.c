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
#include <string.h>
#define N 5
#define ARRAY_SIZE 15
//--------------------------------------------------------------------------
//                           全局变量及函数声明
//--------------------------------------------------------------------------
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
//进制转换
bool convert(int origin, int form, char *to);
bool reverseStr(char *origin);
//素数
int *searchPrimeNum(int within);

//--------------------------------------------------------------------------
//                                 主函数
//--------------------------------------------------------------------------
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
    //--------------------------------------------------------------------------
    //                              进制转换
    //--------------------------------------------------------------------------
    char str[128];
    convert(0, 16, str);
    puts(str);
    reverseStr(str);
    puts(str);
    //--------------------------------------------------------------------------
    //                                素数
    //--------------------------------------------------------------------------
    int *temp = (int *)malloc(1024*sizeof(int));
    temp = searchPrimeNum(1000);
    printf("%d\n", temp[21]);
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
//--------------------------------------------------------------------------
//                              进制转换
//--------------------------------------------------------------------------
bool convert(int origin, int form, char *to) {
    //变10进制 abcd = a*10^3 + b*10^2 + c*10^1 + d*10^0
    //m进制变n进制  abcd  先变10进制 X = a*m^3 + b*m^2 + c*m^1 + d*m^0
    //                      然后 (X/n X/n^2 X/n^3 X/n^4).reverse
    char *conversion = "0123456789ABCDEF";
    int count = 0;
    if(origin == 0) {
        *to = '0';
        *(to+1) = '\0';
        return true;
    }
    while(origin) {
        to[count++] = conversion[origin%form];
        origin /= form;
        //printf("%c  ", conversion[origin%form]);
    }
    to[count] = '\0';
    return true;
}
bool reverseStr(char *origin) {
    const int length = (int)strlen(origin);
    int i;
    for(i=0; i<length/2; i++) {
        char temp = origin[i];
        char temp2 = origin[length-1-i];
        origin[i] = temp2;
        origin[length-1-i] = temp;
        //printf("%c  %c\n", origin[i], origin[length-1-i]);
    }
    return true;
}
//--------------------------------------------------------------------------
//                                素数
//--------------------------------------------------------------------------
int *searchPrimeNum(int within) {
    int temp[1024];
    int i,j,count=0;
    unsigned long timesCount = 0;
    for(i = 2; i < within; i++) {
        for(j = 2; j < i; j++) {
            timesCount++;
            if (!(i%j)) {
                break;
            }
        }
        if(j == i) {
            temp[count] = i;
            printf("%d  \n", temp[count]);
            count++;
        }
    }
    printf("timeCounts = %lu", timesCount);
    return temp;
}
