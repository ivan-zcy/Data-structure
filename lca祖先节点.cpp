/*************************************************************************
	> File Name: cfsTree.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 六  4/13 18:33:07 2019
 ************************************************************************/

#include <algorithm> 
#include <stdio.h>
using namespace std;

#define MAX_M 1000000
#define MAX_N 500000
#define MAX_K 32

//边的结构体
struct Edge {
    int to, next; //to为边的末尾，next为上一个相同起始点的边的下角标
} g[MAX_M + 5];

//链式前向星
int head[MAX_N + 5] = {0};  //head[i]代表以i为起始点的最后一个边的下角标

//边的数量
int cnt = 0;

//链式前向星实现
inline void add(int a, int b) {
    g[++cnt].to = b;   //我们将第cnt条边存到数组的cnt位置处，边的起点是a，终点是b
    g[cnt].next = head[a]; //那么以a为起点的上一个边的位置为head[a]
    head[a] = cnt;     //然后更新head[a]
    return;
}

//gas[i][j]用于存储节点i向上走2^j步到达的节点编号
int gas[MAX_N + 5][MAX_K + 5] = {0};
int deep[MAX_N + 5] = {0};  //存储当前节点的深度

//一次dfs维护gas数组和deep数组
void dfs1(int fa, int inx) {
    

    for (int i = 1; i <= MAX_K; i++) {
        gas[inx][i] = gas[gas[inx][i - 1]][i - 1];
    }

    for (int i = head[inx]; i != 0; i = g[i].next) {
        if (g[i].to == fa) continue;
        int to = g[i].to;
        deep[to] = deep[inx] + 1;
        gas[to][0] = inx;
        dfs1(inx, to);
    }
}

int lca(int x, int y) {
    if (deep[x] < deep[y]) {
        swap(x, y);
    }

    for (int i = MAX_K; i >= 0; i--) {
        if (deep[gas[x][i]] < deep[y]) continue;
        x = gas[x][i];
    }

    if (x == y) return x;

    for (int i = MAX_K; i>= 0; i--) {
        if (gas[x][i] == gas[y][i]) continue;
        x = gas[x][i], y = gas[y][i];
    }
    return gas[x][0];
}

int main () {
    int n, m, s, a, b;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    
    deep[0] = -1;
    dfs1(0, s);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }

    return 0;
}
