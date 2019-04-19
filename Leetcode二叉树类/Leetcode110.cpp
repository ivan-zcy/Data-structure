/*************************************************************************
	> File Name: Leetcode110.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 09:50:46 2019
 ************************************************************************/

//判断是否是平衡二叉树
//方法一：对于每个节点的左右儿子进行dfs查找深度，然后再dfs左子树和右子树是否符合条件，三个同时满足返回真
//方法二：引用传参代表深度，然后一次dfs判断是否为平衡二叉树即可



//方法二代码：
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
    bool istrue(TreeNode* root, int &h) {
        if (!root) {
            h = 1;
            return true;
        }
    
        if(!istrue(root -> left, h)) return false;
        int h1 = h;
        if(!istrue(root -> right, h)) return false;
        int h2 = h;
        
        h = max(h1, h2) + 1;
        
        if (abs(h1 - h2) <= 1) return true;
        
        return false;
    }
    
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return istrue(root, h);
    }
};
