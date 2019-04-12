/*************************************************************************
	> File Name: Leetcode_160.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 10:50:18 2019
 ************************************************************************/

//判断两个链表是否相交
//方法一：对两个链表节点的哈希值映射一下，若存在映射关系则代表相交
//方法二：对两个链表进行遍历确定两个链表的长度，然后进行第二次遍历：长的链表先走差值步，然后两个链表同时走，若存在相同，则代表相交
//方法三：两个链表同时走，若第一个链表走到头，则第一个链表走第二个链表；若第二个链表走到头，则第二个链表走第一个链表。若存在相同，则代表相交


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA) {
            m[headA] ++;
            headA = headA -> next;
        }
        while(headB) {
            if (m[headB]) {
                return headB;
            }
            headB = headB -> next;
        }
        return NULL;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *p = headA;
        ListNode *q = headB;
        
        while(p != q) {
            p = p -> next;
            q = q -> next;
            if (p == NULL) {
                p = headB;
                headB = NULL;
            }
            if (q == NULL) {
                q = headA;
                headA = NULL;
            }
        }
        return p;
    }
};


//方法三的技巧实现
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *p = headA;
        ListNode *q = headB;
        
        //当第二次遍历结束后，两者都变成了NULL
        while(p != q) {
            if(!p) p = headB;
            else p = p -> next;
            if(!q) q = headA;
            else q = q -> next;
        }

        return p;
    }
};