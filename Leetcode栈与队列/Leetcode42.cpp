/*************************************************************************
	> File Name: Leetcode42.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 二  4/23 19:45:30 2019
 ************************************************************************/

//给出n个宽度为1的柱子的高度，问最多存多少水
//方法：利用单调栈来维护（只有保持V型才能存水，
//因此我们需要维护一个单调递减栈，在出栈的时候维护和）

class Solution {
private:
    stack <int> sta;
public:
    int trap(vector<int>& height) {
        int sum = 0;
        
        for (int i = 0; i < height.size(); i++) {
        	//单调递减就增加
            if (sta.empty() || height[sta.top()] > height[i]) {
                sta.push(i);
            } else {	//出现递增就维护

                while(!sta.empty() && height[sta.top()] <= height[i]) {
                    int inx = sta.top();
                    sta.pop();

                    //避免sta.top()访问错误
                    if (sta.empty()) break;
                    
                    int x = min(height[sta.top()] - height[inx], height[i] - height[inx]);
                    int y = i - sta.top() - 1;
                    sum += x * y;
                }

                sta.push(i);
            }
        }
        
        return sum;
            
    }
};
