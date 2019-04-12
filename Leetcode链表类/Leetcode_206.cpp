/*************************************************************************
	> File Name: Leetcode_206.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 16:07:08 2019
 ************************************************************************/

//反转链表
//方法一 迭代法：设置一个虚拟指针指向当前节点的前一个节点，然后依此遍历链表的节点，让当前节点的next指向前一个节点
//方法二
//方法二 递归法：遇到当前节点或当前节点的next为空时，返回当前节点；否则递归下一个节点，递归后将当前节点的next->next设置为当前节点，然后当前节点的next设置为NULL

//迭代法
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
    ListNode* reverseList(ListNode* head) {
        ListNode temp(0);
        temp.next = NULL;
        ListNode *p = head;
        while(p) {
            ListNode *q = p -> next;
            p -> next = temp.next;
            temp.next = p;
            p = q;
        }
        return temp.next;
    }
};


//递归法
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode *root = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return root;
    }
};