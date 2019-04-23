/*************************************************************************
	> File Name: Leetcode84.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 二  4/23 19:51:20 2019
 ************************************************************************/

//求n个连续柱子组成的最大矩形面积
//方法：单调栈来维护


//方法一：
class Solution {
private:
    stack<int>sta;
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        int maxx = 0;
        
        for (int i = 0; i < len; i++) {
            if (sta.empty() || heights[sta.top()] <= heights[i]) {
                sta.push(i);
            } else {
                while(!sta.empty() && heights[sta.top()] > heights[i]) {
                    int inx = sta.top();
                    sta.pop();
                    
                    int s = -1, e = i;
                    if (!sta.empty()) {
                        s = sta.top();
                    }
    
                    maxx = max(maxx, (e - s - 1) * heights[inx]);
                    
                }
                sta.push(i);
            }
        }
        
        int e;
        if (!sta.empty()) {
            e = sta.top();
        }
        
        while(!sta.empty()) {
            int s = -1, inx = sta.top();
            sta.pop();
            
            if (!sta.empty()) {
                s = sta.top();
            }
            maxx = max(maxx, (e - s) * heights[inx]);
        }
        
        return maxx;
    }
};


//方法二：
int largestRectangleArea(int* heights, int heightsSize) {
    
    int *stack = (int *)malloc(sizeof(int) * heightsSize);
    int *left = (int *)malloc(sizeof(int) * heightsSize);
    int *right = (int *)malloc(sizeof(int) * heightsSize);

    //找以该节点往左扩的长度
    int top = -1;
    for (int i = 0; i < heightsSize; i++) {
        while (top != -1 && heights[stack[top]] >= heights[i]) --top;
        left[i] = (top == -1 ? i + 1 : i - stack[top]);
        stack[++top] = i;
    }

    //找以该节点往右扩的长度
    top = -1;
    for (int i = heightsSize - 1; i >= 0; i--) {
        while (top != -1 && heights[stack[top]] >= heights[i]) --top;
        right[i] = (top == -1 ? heightsSize - i : stack[top] - i);
        stack[++top] = i;
    }

    //维护最大范围
    int ans = 0;
    for (int i = 0; i < heightsSize; i++) {
        ans = fmax(ans, (left[i] + right[i] - 1) * heights[i]);
    }

    free(stack);
    free(left);
    free(right);
    return ans;
}