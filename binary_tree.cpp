/*************************************************************************
	> File Name: binary_tree.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 日  4/14 20:24:28 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//树节点
struct Node {
    int val;
    Node *lchild, *rchild;
};

//创建节点
Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));

    p -> val = val;
    p -> lchild = p -> rchild = NULL;
    
    return p;
}

Node *insert(Node *tree, int val) {
    if (tree == NULL) return getNewNode(val);
    if (tree -> val == val) return tree;
    if (tree -> val > val) tree -> lchild = insert(tree -> lchild, val);
    if (tree -> val < val) tree -> rchild = insert(tree -> rchild, val);
    return tree;
}

//前序遍历
void pre_order(Node *tree) {
    if (tree == NULL) return;

    printf("%d ", tree -> val);
    pre_order(tree -> lchild);
    pre_order(tree -> rchild);

    return;
}

//中序遍历
void in_order(Node *tree) { 
    if (tree == NULL) return;

    in_order(tree -> lchild);
    printf("%d ", tree -> val);
    in_order(tree -> rchild);

    return;
}

//后序遍历
void post_order(Node *tree) {
    if (tree == NULL) return;

    post_order(tree -> lchild);
    post_order(tree -> rchild);
    printf("%d ", tree -> val);
    
    return;
}

//释放树
void clear(Node *tree) {
    if (tree == NULL) return;

    clear(tree -> lchild);
    clear(tree -> rchild);

    free(tree);

    return;
}

int main () {
    #define MAX_OP 20
    srand(time(0));
    Node *root = NULL;

    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        printf("insert %d to binary search tree\n", val);
        root = insert(root, val);
        pre_order(root), printf("\n");
        in_order(root), printf("\n");
        post_order(root), printf("\n");
    }

    return 0;
}
