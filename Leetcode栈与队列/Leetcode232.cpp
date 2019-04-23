/*************************************************************************
	> File Name: Leetcode232.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 四  4/18 18:54:37 2019
 ************************************************************************/

//栈实现队列
//方法一：两个队列，一个队列用于存，另一个队列用于反转（删除头，返回头操作），之后再反转回去
//方法二：把队列反转，需要用一个临时队列

//方法一代码(适用于添加操作多，删除和获取栈头次数少的情况)：
class MyQueue {
private:
    stack<int> p, q;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        p.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!p.empty()) {
            q.push(p.top());
            p.pop();
        }
        
        int k = q.top();
        q.pop();
        
        while(!q.empty()) {
            p.push(q.top());
            q.pop();
        }
        
        return k;
    }
    
    /** Get the front element. */
    int peek() {
        while(!p.empty()) {
            q.push(p.top());
            p.pop();
        }
        
        int k = q.top();
        
        while(!q.empty()) {
            p.push(q.top());
            q.pop();
        }
        
        return k;
    
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return p.empty();   
    }
};



//方法二(适用于删除和获取栈头次数多，添加次数少的情况)：
class MyQueue {
private:
    stack<int> p, q;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!p.empty()) {
            q.push(p.top());
            p.pop();
        }
        
        q.push(x);
        
        while(!q.empty()) {
            p.push(q.top());
            q.pop();
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int k = peek();
        p.pop();
        
        return k;
    }
    
    /** Get the front element. */
    int peek() {
        return p.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return p.empty();   
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */