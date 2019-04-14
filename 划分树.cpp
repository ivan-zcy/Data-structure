/*************************************************************************
	> File Name: cfsTree.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 六  4/13 18:33:07 2019
 ************************************************************************/

#include <algorithm> 
#include <stdio.h>
using namespace std;

//边的数量
#define MAX_M 1000000
//节点的数量
#define MAX_N 500000
//最大走2^MAX_K步
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
int father[MAX_N + 5] = {0}; //存储当前节点的符节点
int val[MAX_N + 5] = {0};   


//一次dfs维护gas数组、deep数组、father数组
void dfs1(int fa, int inx) {

    father[inx] = fa;

    //原因：2^(i - 1) + 2^(i - 1) = 2 ^ i
    for (int i = 1; i <= MAX_K; i++) {
        gas[inx][i] = gas[gas[inx][i - 1]][i - 1];
    }

    for (int i = head[inx]; i != 0; i = g[i].next) {
        //如果下一个节点为父节点，则跳过
        if (g[i].to == fa) continue;

        int to = g[i].to;

        deep[to] = deep[inx] + 1;
        //当前节点跳一步为父节点
        gas[to][0] = inx;

        dfs1(inx, to);
    }
}

//lca算法
int lca(int x, int y) {

    //找到较深的节点，然后向上走到和较浅的一个深度
    if (deep[x] < deep[y]) {
        swap(x, y);
    }

    for (int i = MAX_K; i >= 0; i--) {
        if (deep[gas[x][i]] < deep[y]) continue;
        x = gas[x][i];
    }

    //如果较浅节点极为较深节点的祖宗节点，则直接返回
    if (x == y) return x;

    //否则两个同时走（这种走法能保证两个节点分别正好走到公共祖宗节点的前一个节点）
    for (int i = MAX_K; i >= 0; i--) {
        if (gas[x][i] == gas[y][i]) continue;
        x = gas[x][i];
        y = gas[y][i];
    }

    return gas[x][0];
}


//求以inx为根节点的字数的val和
//可以改成求区间和（树状数组或者线段树）
int query(int inx) {
    int ans = 0;

    for (int i = head[inx]; i; i = g[i].next) {
        if (g[i].to == father[inx]) continue;
        ans += query(g[i].to);
    }

    ans += val[inx];

    return ans;
}

int main () {
    //n个节点，m次操作，s为根节点
    int n, m, s, a, b, c, d;

    scanf("%d%d%d", &n, &m, &s);

    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    
    //需要对0节点设置为树深度为-1
    deep[0] = -1;
    dfs1(0, s);
    
    for (int i = 0; i < m; i++) {
        //a代表操作方式
        scanf("%d", &a);

        switch(a) {
            //对节点b到节点c的路径全部增加d
            case 1: {
                scanf("%d%d%d", &b, &c, &d);
                val[b] += d;
                val[c] += d;

                int temp = lca(b, c);
                val[temp] -= d;
                val[father[temp]] -= d;

                break;
            }

            //查询b节点的值
            case 2: {
                scanf("%d", &b);
                printf("%d\n", query(b));
            }
        
        }
    }

    return 0;
}
