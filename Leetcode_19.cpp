/*************************************************************************
	> File Name: Leetcode_19.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 09:19:32 2019
 ************************************************************************/

//删除链表的倒数第N个节点
//(1)为了避免删除第一个节点的特殊操作，我们可以设置一个虚拟头节点
//方法一：我们可以第一次遍历得到链表的长度len，然后第二遍遍历找第len - N + 1个节点
//方法二：我们可以使用递归的方式，参数为上一个节点的地址和当前节点，返回值为之后有多少个节点。若返回值 == N - 1，我们就删除该节点
//方法三：利用两个指针，第一个指针走到N+1步，也就是走到N+2节点处，然后两个指针同时走，当第一个指针走到空后，第二个指针就是待删除节点的上一个位置，然后就可以删除下一个节点了

//方法二代码：
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(ListNode *last, ListNode *now, int len) {
        if (now == NULL) return 0;
        int k = dfs(now, now -> next, len);
        if (k == len - 1) {
            last -> next = now -> next;
            delete(now);
        }
        return k + 1;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) return NULL;
        
        //虚拟头指针
        ListNode temp(0);
        temp.next = head;
        
        //遍历
        dfs(&temp, temp.next, n);
        
        return temp.next;
    }
};


//方法三代码：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //特判特殊情况
    if (head == NULL || n <= 0) return NULL;
    
    //设置虚拟指针
    struct ListNode temp;
    temp.next = head;
    
    struct ListNode *p = &temp, *q = &temp;
        
    while(n && p) {
        p = p -> next;
        n--;
    }
    if (n != 0 || p == NULL) {
        return temp.next;
    }
    
    p = p -> next;
    
    while(p) {
        p = p -> next;
        q = q -> next;
    }
    
    //删除节点
    p = q -> next;
    q -> next = p -> next;
    free(p);
    
    return temp.next;
}