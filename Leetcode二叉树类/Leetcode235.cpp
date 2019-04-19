/*************************************************************************
	> File Name: Leetcode235.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 17:41:59 2019
 ************************************************************************/

//二叉搜索树的最近公共祖先
//方法一：递归从上往下，若都小于该节点递归左节点，若都大于递归右节点，否则直接返回
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return NULL;
        }
        
        if (root -> val < p -> val && root -> val < q -> val) {
            return lowestCommonAncestor(root -> right, p, q);
        } else if(root -> val > p -> val && root -> val > q -> val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        
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
    queue<TreeNode*>que;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return NULL;
        }
        
        que.push(root);
        while(!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            if (temp -> val < p -> val && temp -> val < q -> val) {
                if (temp -> right) {
                    que.push(temp -> right);
                }
            } else if (temp -> val > p -> val && temp -> val > q -> val) {
                if (temp -> left) {
                    que.push(temp -> left);
                }
            } else {
                return temp;
            }
        }
        
        return NULL;
    }
};
