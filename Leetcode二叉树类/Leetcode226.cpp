/*************************************************************************
	> File Name: Leetcode226.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 15:52:44 2019
 ************************************************************************/

//翻转二叉树
//方法一：递归从上往下递归替换
//方法二：非递归


//方法一：
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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        
        TreeNode *temp = root -> left;
        
        root -> left = invertTree(root -> right);
        root -> right = invertTree(temp);
        return root;
    }
};



//方法二：
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
    queue<TreeNode *>que;
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        
        que.push(root);
        while(!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            
            TreeNode *p = temp -> left;
            temp -> left = temp -> right;
            temp -> right = p;
            
            if (temp -> left) que.push(temp -> left);
            if (temp -> right) que.push(temp -> right);
        }
        
        return root;
    }
};