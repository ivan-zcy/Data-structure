/*************************************************************************
	> File Name: stack.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 日  4/14 18:54:44 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//定义栈结构
struct Stack {
    int *data;
    int length, top;
};

//初始化栈
Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s -> length = n;
    s -> top = -1;
    s -> data = (int *)malloc(sizeof(int) * n);
    return s;
}

//若空返回真
int empty(Stack *s) {
    return s -> top == -1;
}

//返回头节点
int top(Stack *s) {
    if (empty(s)) return -1;
    return s -> data[s -> top];
}

//添加到栈
void push(Stack *s, int val) {
    if (s -> top == s -> length - 1) return;

    s -> top ++;
    s -> data[s -> top] = val;

    return;
}

//从栈头移除头
void pop(Stack *s) {
    if (empty(s)) return;

    s -> top --;
    
    return;
}

//释放栈
void clear(Stack *s) {
    if (s == NULL) return;

    free(s -> data);
    free(s);

    return;
}

//全部输出
void output(Stack *s) {
    printf("[");
    for (int i = s -> top; i >= 0; i--) {
        printf(" %d", s -> data[i]);
    }
    printf(" ]\n");

    return;
}

int main () {
    srand(time(0));
    #define MAX_OP 20
    Stack *s = init(8);
    
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2, val = rand() % 100;
        switch(op) {
            case 0: {
                printf("push %d to stack\n", val);
                push(s, val);
                break;
            }
            case 1: {
                printf("pop %d from stack\n", top(s));
                pop(s);
            }
        }
        output(s);
    }
    
    clear(s);

    return 0;
}
