/*************************************************************************
	> File Name: Leetcode114.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 11:28:59 2019
 ************************************************************************/

//将二叉树转变为单向链表（前序规则）
//方法一：递归，利用一个vec进行存进行前序遍历，然后设置
//方法二：利用栈进行非递归


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
private:
    vector<TreeNode *>vec;
public:
    void dfs(TreeNode *root) {
        
        vec.push_back(root);
        if (root -> left) dfs(root -> left);
        if (root -> right) dfs(root -> right);
    }
    
    void flatten(TreeNode* root) {
        if (!root) return;
        
        dfs(root);
        
        for (int i = 0; i < vec.size() - 1; i++) {
            vec[i] -> right = vec[i + 1];
            vec[i] -> left = NULL;
        }
        vec[vec.size() - 1] -> left = NULL;
        vec[vec.size() - 1] -> right = NULL;
        
        return;
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
    stack<TreeNode *>sta;
    vector<TreeNode *>vec;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        TreeNode *p = root;
        TreeNode *temp = new TreeNode(0);
        
        while(!sta.empty() || p) {
            while(p) {
                vec.push_back(p);
                sta.push(p);
                p = p -> left;
            }
            
            if(!sta.empty()) {
                p = sta.top();
                sta.pop();
                p = p -> right;
            }
            
        }
        
        for (int i = 0; i < vec.size() - 1; i++) {
            vec[i] -> left = NULL;
            vec[i] -> right = vec[i + 1];
        }
        vec[vec.size() - 1] -> left = NULL;
        
        return ;
    }
};
