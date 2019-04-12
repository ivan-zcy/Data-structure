/*************************************************************************
	> File Name: Leetcode_237.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 11:54:23 2019
 ************************************************************************/

//只给定待删除节点，让你从链表中删除该节点，前提条件：该删除节点不是链表的最后一个节点
//由于我们不知道待删除节点的前一个节点，因此我们可以把该节点的下一个节点的值赋值给待删除节点，然后让待删除节点的next指向下一个节点的下一个节点，这样我们删除待删除节点的下一个节点即可

//代码实现

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p = node -> next;
        node -> val = p -> val;
        node -> next = p -> next;
        delete(p);
    }
};