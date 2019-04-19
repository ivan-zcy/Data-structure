/*************************************************************************
	> File Name: Leetcode111.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 10:11:38 2019
 ************************************************************************/

//求二叉树的最小深度（最小深度是指从根节点到叶节点的最短距离）
//方法一：递归，若节点存在左右节点，则该节点为左右节点深度的最小值+1；否则为左右节点深度的最大值+1
//方法二：非递归层次遍历，遍历到第一个出现无左右节点的节点深度返回


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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        if (root -> left && root -> right) {
            return min(minDepth(root -> left), minDepth(root -> right)) + 1;
        }
        
        return max(minDepth(root -> left), minDepth(root -> right)) + 1;
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        int deep = 0;
        que.push(root);
        while(!que.empty()) {
            deep ++;
            int len = que.size();
            
            for (int i = 0; i < len; i++) {
                TreeNode *temp = que.front();
                que.pop();
                if (!temp -> left && !temp -> right) {
                    return deep;
                }
                if (temp -> left) {
                    que.push(temp -> left);
                }
                if (temp -> right) {
                    que.push(temp -> right);
                }
            }
        }
        return deep;
    }
    
};