/*************************************************************************
	> File Name: Leetcode113.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 10:53:18 2019
 ************************************************************************/

//给出一个二叉树和一个目标和，找到所有根节点到叶子节点路径等于目标和的路径
//方法：递归dfs，到根节点判断是否相同，相同就加进去


//代码：
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> vec;
    vector<int> temp;
public:
    void dfs(TreeNode *root, int &now, int &sum) {
        now += root -> val;
        temp.push_back(root -> val);
        
        //当节点为叶节点时
        if (!root -> left && !root -> right) {
            if (now == sum) {
                vec.push_back(temp);
            }
            now -= root -> val;
            temp.pop_back();
            return;
        }
        
        //当节点不为叶节点
        if (root -> left) {
            dfs(root -> left, now, sum);
        }
        
        if (root -> right) {
            dfs(root -> right, now, sum);
        }
        
        now -= root -> val;
        temp.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return vec;
        
        int now = 0;
        dfs(root, now, sum);
        
        return vec;
    }
};