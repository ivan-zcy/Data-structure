/*************************************************************************
	> File Name: Leetcode102.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 四  4/18 21:12:59 2019
 ************************************************************************/

//二叉树的层次遍历
//方法一：非递归遍历（利用一个变量deep记录深度，一个滚动数组num[2]记录每一层的个数）
//方法二：递归遍历 (参数传深度deep，再用一个num记录当前最深的深度，只要deep > num就再push一个vector一维数组)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//方法一：
class Solution {
private:
    vector <vector<int>> vec;
    queue <TreeNode *> que;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vec;
        
        vector<int> temp;
        
        que.push(root);
        int deep = 1;
        int num[2] = {0, 1};
        
        while(!que.empty()) {
            TreeNode *p = que.front();
            que.pop();
            temp.push_back(p -> val);
            num[deep % 2] --;
            
            if (!num[deep % 2]) {
                vec.push_back(temp);
                temp.clear();
            }
            
            if (p -> left) {
                que.push(p -> left);
                num[(deep + 1) % 2]++;
            }
            if (p -> right) {
                que.push(p -> right);
                num[(deep + 1) % 2]++;
            }
            
            if (!num[deep % 2]) deep ++;
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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return vec;
        }
        
        dfs(root, 0);
        
        return vec;
    }
};
