//
//  main.c
//  Basic
//
//  Created by 徐伟达 on 2017/5/4.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//some basic algorithm
int main(int argc, const char * argv[]) {
    int a = 0;
    //char temp = ' ';
    int b[128] = {};
    int count = 0;
    char str[128] = "0";
    //char getCor = ' ';
    
    do {
        printf("count = %d\n", count);
        /*scanf("%c", &temp);
        scanf("%c", &getCor);
        b[count] = (int)(temp-'0');
        count++;*/
        gets(str);
        b[count] = atoi(str);
        count++;
        
        
    }while (*str != 'q' && count < 128);
    
    printf("%d\n", count);
    for(a = 0; a < count-2; a += 3) {
        printf("b[%d]: %d\tb[%d]: %d\tb[%d]: %d\t\n", a, b[a], a+1, b[a+1], a+2, b[a+2]);
    }
    int maxNum = 0;
    for(a = 0; a < count; a++) {
        if(b[a] > maxNum) {
            maxNum = b[a];
        }
    }
    printf("%d\n", maxNum);
    //scanf("%d", &a);
    //printf("your num is: %d\n", a);
    printf("Hello, World!\n");
    return 0;
}
