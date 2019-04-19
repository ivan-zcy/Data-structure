/*************************************************************************
	> File Name: Leetcode105.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 08:55:40 2019
 ************************************************************************/

//根据前序、中序构造二叉树
//递归方式，参数传6个（前序、中序数组，前序开始结尾下标，中序开始结尾下标），当开始>结束为终止条件


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& p, int ps, int pe, vector<int>& q, int qs, int qe) {
        if (ps > pe || qs > qe) return NULL;
        
        TreeNode *temp = new TreeNode(p[ps]);
        int inx = qs;
        
        for (int i = qs; i <= qe; i++) {
            if (q[i] == p[ps]) {
                inx = i;
                break;
            }
        }
        
        //左个数：inx - qs, 右个数：qe - inx
        temp -> left = dfs(p, ps + 1, ps + inx - qs, q, qs, inx - 1);
        temp -> right = dfs(p, ps + inx - qs + 1, pe, q, inx + 1, qe);
            
        return temp;
    }
};