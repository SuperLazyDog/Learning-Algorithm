//
//  main.c
//  Array
//
//  Created by 徐伟达 on 2017/5/9.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include <stdio.h>
#define N 5

int main(int argc, const char * argv[]) {
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
    return 0;
}
