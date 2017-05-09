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
    char getCor = ' ';
    int i, j, k;
    
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
    printf("hello");
    
    //--------------------------------------------------------------------
    //                           2017/05/09
    //--------------------------------------------------------------------
    int n = 0;
    puts("要几行的正三角形？");
    scanf("%d", &n);
    scanf("%c", &getCor);
    printf("你要的是%d行的三角形\n", n);
    /* n = 4的情况
         *
        ***
       *****
      *******
     */
    /*
     总结： 这种方法每次都要判断j是不是1，影响效率
     */
    puts("//--------------------------------------------------------------------");
    puts("//                            方法一");
    puts("//--------------------------------------------------------------------");
    printf("先绘制每行第一个星， 然后绘制余下的2n个\n");
    for(a = 0; a < n; a++) {
        for(j = n-a; j > 0; j--) {//绘制该行第一个星
            if(j == 1) {
                printf("*");
            }else {
                printf(" ");
            }
        }
        for(j = 0; j < a; j++) {//余下2n个，在第一个后面直接画
            printf("**");
        }
        printf("\n");
    }
    puts("//--------------------------------------------------------------------");
    puts("//                            方法二");
    puts("//--------------------------------------------------------------------");
    printf("先绘制每行第一个星之前的空格， 然后绘制余下的2n+1个\n");
    for(a = 0; a < n; a++) {
        for(j = 0; j < n-a-1; j++) {//绘制该行第一个星之前的空格
            printf(" ");
        }
        for(j = 0; j < 2*a+1; j++) {//绘制该行的全部星(2n+1)
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
