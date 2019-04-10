/*************************************************************************
	> File Name: List.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 二  4/ 9 20:37:14 2019
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//链表节点的结构体表示
typedef struct LinkListNode {
    int data;
    struct LinkListNode *next;
}LinkListNode;

//链表的结构体表示
typedef struct LinkList {
    //head称为虚拟头节点（不用于存储数据）
    struct LinkListNode head;
    int length;
}LinkList;


//链表节点的初始化
LinkListNode * getNewNode(int val) {
    LinkListNode *p = (LinkListNode *)malloc(sizeof(LinkListNode));

    p -> data = val;
    p -> next = NULL;

    return p;
}

//链表的初始化
LinkList *init() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    
    l -> length = 0;
    l -> head.next = NULL;

    return l;
}

//释放内存
void clear(LinkList *l) {
    if (l == NULL)
        return;

    LinkListNode *p = l -> head.next;

    while(p) {
        LinkListNode *old = p;
        p = p -> next;
        free(old);
    }
    
    l -> head.next = NULL;
    free(l);

    return;
} 

//插入操作
int insert(LinkList *l, int inx, int val) {
    if (l == NULL)
        return -1;
    if (inx < 0 || inx > l -> length) 
        return -1;

    LinkListNode *new_node = getNewNode(val);

    //走到待插入节点的前一个位置
    LinkListNode *p = &(l -> head);
    while(inx--) {
        p = p -> next;   
    }
    
    new_node -> next = p -> next;
    p -> next = new_node;
    l -> length ++;

    return 0;
}

//删除链表节点
int del(LinkList *l, int inx) {
    if (l == NULL) 
        return -1;
    if (inx < 0 || inx >= l -> length) 
        return -1;

    LinkListNode *p = &(l -> head);
    while(inx --) {
        p = p -> next;
    }

    LinkListNode *old = p -> next;
    p -> next = old -> next;
    l -> length --;

    free(old);
    return 0;
}

//修改链表节点
int revise(LinkList *l, int inx, int val) {
    if (l == NULL) 
        return -1;
    if (inx < 0 || inx >= l -> length) 
        return -1;
    
    LinkListNode *p = l -> head.next;
    while(inx --) {
        p = p -> next;
    }
    
    p -> data = val;
    
    return 0;
}

//遍历链表
void output(LinkList *l) {
    LinkListNode *p = l -> head.next;

    printf("head ->");
    while(p) {
        printf(" %d ->", p -> data);
        p = p -> next;
    }
    printf(" NULL\n");

    return;
}

//查找元素
int search(LinkList *l, int val) {
    if (l == NULL)
        return -1;

    int sum = 7, inx = 0;
    LinkListNode *p = l -> head.next;

    while(p && p -> data != val) {
        sum += 4;
        
        int k = p -> data;
        while (k) {
            sum ++;
            k /= 10;
        }

        p = p -> next;
        inx ++;
    }

    if (p == NULL) {
        return -1;
    }
    
    for (int i = 0; i <= sum; i++) {
        printf(" ");
    }
    printf("↑\n");

    return inx;
}

int main () {
    #define MAXN 20
    LinkList *l = init();
    int inx, val, op;

    for (int i = 0; i < MAXN; i++) {
        
        op = rand() % 4;
        inx = rand() % (l -> length + 1);
        val = rand() % 10;

        switch (op) {
            case 0: {
                printf("insert %d to Linklist at %d is %s\n", val, inx, insert(l, inx, val) == 0? "true": "false");
                output(l);
                break;
            }
            case 1: {
                printf("delete Linklist at %d is %s\n", inx, del(l, inx) == 0? "true": "false");
                output(l);
                break;
            }
            case 2: {
                printf("revise %d to Linklist at %d is %s\n", val, inx, revise(l, inx, val) == 0? "true": "false");
                output(l);
                break;
            }
            case 3: {
                output(l);
                inx = search(l, val);
                printf("search %d in Linklist is %s\n", val, inx == -1? "false": "true");
                break;
            }
            default: {
                fprintf(stderr, "op faild\n");
            }
        }
    }

    return 0;
}
