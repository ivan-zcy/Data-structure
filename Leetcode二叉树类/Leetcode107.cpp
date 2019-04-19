/*************************************************************************
	> File Name: Leetcode107.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/19 09:14:10 2019
 ************************************************************************/

//二叉树层次遍历，从下往上
//方法一：递归+交换（反转）
//方法二：非递归+交换（反转）


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
    vector <vector<int>> vec;
    int num = -1;
    
public:
    void dfs(TreeNode* root, int deep) {
        if (deep > num) {
            vec.push_back(vector<int>());
            num ++;
        }
        
        vec[deep].push_back(root -> val);
        
        if (root -> left) {
            dfs(root -> left, deep + 1);
        }
        
        if (root -> right) {
            dfs(root -> right, deep + 1);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) {
            return vec;
        }
        
        dfs(root, 0);
        
        for (int i = 0; i < (num + 1) / 2; i++) {
            vector<int> temp = vec[i];
            vec[i] = vec[num - i];
            vec[num - i] = temp;
        }
        
        return vec;
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
    vector<vector<int>> vec;
    vector<int> temp;
    queue<TreeNode *>que;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vec;
        
        que.push(root);
        int deep = 0;
        
        while(!que.empty()) {
            int len = que.size();
            deep ++;
        
            for (int i = 0; i < len; i++) {
                TreeNode *k = que.front();
                temp.push_back(k -> val);
                if (k -> left) {
                    que.push(k -> left);
                }
                if (k -> right) {
                    que.push(k -> right);
                }
                que.pop();
            }
            
            vec.push_back(temp);
            temp.clear();
        }
        
        for (int i = 0; i < deep / 2; i++) {
            temp = vec[i];
            vec[i] = vec[deep - 1 - i];
            vec[deep - 1 - i] = temp;
        }
        
        return vec;
    }
};