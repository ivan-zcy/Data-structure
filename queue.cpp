/*************************************************************************
	> File Name: queue.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 六  4/13 20:49:28 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//队列
struct Queue {
    int count, length, head, tail;
    int *data;
};

//初始化
Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q -> data = (int *)malloc(sizeof(int) * n);
    q -> length = n;
    q -> count = 0;
    q -> head = 0;
    q -> tail = 0;
    return q;
}

//返回头节点
int front(Queue *q) {
    return q -> data[q -> head];
}

//若空返回真
int empty(Queue *q) {
    return q -> count == 0;
}

//添加到队列
void push(Queue * q, int val) {
    if (q -> count == q -> length) return;

    q -> data[(q -> tail) ++] = val;

    if (q -> tail >= q -> length) {
        q -> tail -= q -> length;
    }
    q -> count ++;

    return;
}

//删除队头元素
void pop(Queue *q) {
    if (q -> count == 0) return;

    q -> head ++;
    if (q -> head >= q -> length) {
        q -> head -= q -> length;
    }
    q -> count --;

    return;
}

//释放队列
void clear(Queue *q) {
    if (q == NULL) return;
    free(q -> data);
    free(q);
    return;
}

//全部输出
void output(Queue *q) {
    printf("[");
    for (int i = 0; i < q -> count; i++) {
        int inx = (q -> head + i) % q -> length;
        printf(" %d", q -> data[inx]);
    }
    printf(" ]\n");
    return;
}


int main () {
    srand(time(0));
    #define MAX_OP 20
    Queue *q = init(5);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, val = rand() % 100;
        switch(op) {
            case 0: {
                printf("insert %d to queue\n", val);
                push(q, val);
                break;
            }
            case 1: {
                printf("pop %d form queue\n", front(q));
                pop(q);
                break;
            }
            case 2: {
                printf("front %d form queue\n", front(q));
                break;
            }
            case 3: {
                output(q);
            }
        }
    }
    clear(q);
    return 0;
}
