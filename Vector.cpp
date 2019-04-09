/*************************************************************************
	> File Name: Sequence_table.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 二  4/ 9 19:05:49 2019
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//结构体表示
typedef struct Vector {
    int *data;   //顺序表存储
    int size, length;   //顺序表的大小和当前长度
} Vector;

//初始化
Vector *init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));

    p -> data = (int *)malloc(sizeof(int));
    p -> size = n;
    p -> length = 0;

    return p;
}

//插入
int insert(Vector *v, int inx, int val) {
    if (v -> length >= v -> size) 
        return -1;
    if (inx < 0 || inx > v -> length) 
        return -1;
    
    for (int i = v -> length - 1; i >= inx; i--) {
        v -> data[i + 1] = v -> data[i];
    }

    v -> data[inx] = val;
    v -> length++;

    return 0;
}

//删除单个元素
int del(Vector *v, int inx) {
    if (inx < 0 || inx >= v -> length) 
        return -1;

    for (int i = inx + 1; i < v -> length; i++) {
        v -> data[i - 1] = v -> data[i];
    }

    v -> length --;
    
    return 0;
}

//删除
void clear(Vector *v) {
    if (v == NULL) 
        return;
    
    free(v -> data);
    free(v);
    
    return ;
}

//输出整个Vector
void output(Vector *v) {
    printf("arr = [ ");
    
    for (int i = 0; i < v -> length; i++) {
        printf("%d%c", v -> data[i], i == v -> length - 1? ' ': ',');
    }
    
    printf("]\n");
}

int main () {
    #define MAX_OP 20
    int op, inx, val;
    
    //初始化
    Vector *v = init(MAX_OP);
    
    //进行MAX_OP次操作
    for (int i = 0; i < MAX_OP; i++) {
        //op代表操作，inx代表下角标，val代表存储信息，随即生成
        op = rand() % 2;
        inx = rand() % (v -> length  + 3) - 1;  //一定概率生成非法值
        val = rand() % 100;
        
        //根据不同操作执行不同函数
        switch (op) {
            case 0: {
                printf("insert %d to vector %d is %s\n", val, inx, insert(v, inx, val) == 0? "true": "false");
                output(v);
                break;
            }

            case 1: {
                printf("delete %d from vector is %s\n", inx, del(v, inx) == 0? "ture": "false");
                output(v);
                break;
            }

            default:
                fprintf(stderr, "wrong op: %d\n", op);
        }
    }

    //释放掉内存
    clear(v);

    return 0;
}
