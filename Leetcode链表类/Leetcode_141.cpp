/*************************************************************************
	> File Name: Leetcode_141.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 10:27:44 2019
 ************************************************************************/

//判断是否存在环形链表
//先设置虚拟头节点
//方法一：对于每个节点的地址进行map映射，若已存在映射关系则证明成环
//方法二：对于遍历过的节点把节点的next指向自己，遍历过程中若存在指向自己的节点则证明成环
//方法三：利用快慢指针，慢指针一次走一个单位，快指针一次走两个单位，若出现快慢指针相同，则成环


//方法一
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    map<ListNode *, int>m;
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (m[head] > 0) return true;
        m[head] ++;
        return hasCycle(head -> next);
    }
};


//方法二
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head -> next == head) return true;
        ListNode *p = head -> next;
        head -> next = head;
        return hasCycle(p);
    }
};


//方法三
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        ListNode temp(0);
        temp.next = head;
        ListNode *p = &temp, *q = &temp;
        while(q && q -> next != NULL) {
            p = p -> next;
            q = q -> next -> next;
            if (p == q) return true;
        }
        return false;
    }
};
