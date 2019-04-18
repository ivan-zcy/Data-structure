/*************************************************************************
	> File Name: Leetcode101.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 四  4/18 20:20:23 2019
 ************************************************************************/

//判断对称二叉树
//方法一：递归（函数包含两个参数）
//方法二：非递归（注意存BFS的次序，还有根存两次）


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
    bool isTrue(TreeNode *l, TreeNode *r) {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l -> val != r -> val) return false;
        return isTrue(l -> left, r -> right) && isTrue(l -> right, r -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isTrue(root -> left, root -> right);
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
    queue<TreeNode*> que;
public:
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        que.push(root);
        que.push(root);
        
        while(!que.empty()) {
            TreeNode *p = que.front(); que.pop();
            TreeNode *q = que.front(); que.pop();
            
            if ((p && !q) || (!p && q)) return false;
            if (p && q) {
                if (p -> val != q -> val) return false;
                que.push(p -> left);
                que.push(q -> right);
                que.push(p -> right);
                que.push(q -> left);
            }
            
        }
        
        return true;
    }
};
