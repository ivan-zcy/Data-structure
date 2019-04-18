/*************************************************************************
	> File Name: Leetcode225.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 四  4/18 18:35:39 2019
 ************************************************************************/

//用两个队列实现栈

//方法：把队列反转即可，需要一个临时队列

class MyStack {
private:
    queue <int> p, q;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        p.push(x);
        
        while(!q.empty()) {
            p.push(q.front());
            q.pop();
        }
        
        while(!p.empty()) {
            q.push(p.front());
            p.pop();
        }
        
        return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int k = top();
        q.pop();
        return k;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
