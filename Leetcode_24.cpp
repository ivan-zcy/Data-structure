/*************************************************************************
	> File Name: Leetcode_24.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 10:13:48 2019
 ************************************************************************/

//两两交换链表中的节点
//我们设置虚拟头节点
//方法一：我们利用一个变量进行计数，若遇到奇数，若存在下一个节点，就和下一个节点进行数值的交换
//方法二：我们可以利用两个临时指针（p用来指向要交换的两个节点的之前节点，q用来指向要交换的两个节点的第一个节点），来实现对实际节点的交换


//方法二实现
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
    ListNode* swapPairs(ListNode* head) {
        //虚拟头节点
        struct ListNode temp(0);
        temp.next = head;
        
        //两个临时指针
        struct ListNode *p = &temp, *q = temp.next;
        while(q && q -> next) {
            p -> next = q -> next;
            q -> next = p -> next -> next;
            p -> next -> next = q;
            p = q;
            q = q -> next;
        }
        
        return temp.next;
    }
};