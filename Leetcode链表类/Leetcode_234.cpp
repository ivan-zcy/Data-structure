/*************************************************************************
	> File Name: Leetcode_234.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 16:25:26 2019
 ************************************************************************/

//判断链表是否为回文链表
//方法一：遍历链表将元素存到数组中，然后判断数组是否为回文数组
//方法二：递归遍历链表，将元素存到队列中，然后在递归后判断队头是否和当前节点val相同
//方法三：将后半段或者前半段链表反转，然后用两个指针同时遍历，若相同则为回文链表

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
private:
    queue<int>que;
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        que.push(head -> val);
        bool k = isPalindrome(head -> next);
        if (que.front() != head -> val) {
            k = false;
        }
        que.pop();
        return k;
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
    //获取链表长度
    int getlen(ListNode *head) {
        int num = 0;
        while(head) {
            num ++;
            head = head -> next;
        }
        return num;
    }    
    
    //反转链表
    void r(ListNode *k, ListNode *p) {
        ListNode *last = NULL, *q;
        while(p) {
            q = p -> next;
            p -> next = last;
            last = p;
            p = q;
        }
        k -> next = last;
    }
    
    bool isPalindrome(ListNode* head) {

    	//获取链表长度并特判
        int len = getlen(head);
        if (len == 0 || len == 1) return true;


        int step = (len + 1) / 2 - 1;
        ListNode *p = head;
        while(step --) {
            p = p -> next;
        }

        //反转后半段链表
        r(p, p -> next);

        //两个指针分别遍历前半段和后半段
        ListNode *q = head;
        p = p -> next;
        for (int i = 1; i <= len / 2; i++) {
            if(p -> val != q -> val) return false;
            p = p -> next;
            q = q -> next;
        }
        return true;
    }
};