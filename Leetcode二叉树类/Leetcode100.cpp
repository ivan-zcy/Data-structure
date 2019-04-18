/*************************************************************************
	> File Name: Leetcode100.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 四  4/18 19:20:48 2019
 ************************************************************************/

//判断两个树是否相同
//方法一：递归判断
//方法二：非递归判断

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p -> val != q -> val) return false;
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
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
    queue <TreeNode *> t1, t2;
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        
        t1.push(p);
        t2.push(q);
        
        while(!t1.empty() && !t2.empty()) {
            TreeNode *temp1 = t1.front();
            TreeNode *temp2 = t2.front();
            t1.pop();
            t2.pop();
            
            if (temp1 -> val != temp2 -> val) return false;
            
            if (temp1 -> left && temp2 -> left) {
                t1.push(temp1 -> left);
                t2.push(temp2 -> left);
            } else if (temp1 -> left || temp2 -> left)  {
                return false;
            }
            
            if (temp1 -> right && temp2 -> right) {
                t1.push(temp1 -> right);
                t2.push(temp2 -> right);
            } else if (temp1 -> right || temp2 -> right)  {
                return false;
            }
            
        }
        
        if (t1.empty() && t2.empty()) return true;
        
        return false;
        
    }
};