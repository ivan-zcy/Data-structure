/*************************************************************************
	> File Name: Leetcode236.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 18:50:12 2019
 ************************************************************************/

//二叉树求公共最近祖先
//方法一：递归（最近祖先有一个特点，要么是左右点各有一个节点，要么是祖先是其中一个节点）


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        
        if (root == p || root == q) {
            return root;
        }
        
        TreeNode *temp1 = lowestCommonAncestor(root -> left, p, q);
        TreeNode *temp2 = lowestCommonAncestor(root -> right, p, q);
        
        if (temp1 && temp2) return root;
        if (temp1) return temp1;
        if (temp2) return temp2;
        
        return NULL;
    }
};

