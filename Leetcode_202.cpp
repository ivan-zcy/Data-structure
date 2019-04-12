/*************************************************************************
	> File Name: Leetcode_202.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 五  4/12 11:36:36 2019
 ************************************************************************/

//对于一个整数，每次将该数替换为它每个位置的数字的平方和，若最终能得到1，就为快乐数，让我们判断一个数是否为快乐数
//对于int型正整数1～2e9左右，因此转变完一次后最大为730（由1999999999得到），因此这个题的最大范围为730。它具备链表的性质（即通过一个状态能唯一的确定下一个状态）
//方法一：我们只要转变次数超过730还没有得到1，那么2～730中必定存在重复的数，也就代表着一定成环，因此不是快乐数
//方法二：利用map映射，若某个数经历变换之后某个状态出现两次，则不是快乐数
//方法三：就是将其当作链表，利用快慢指针原理判断其是否存在环

//方法一
class Solution {
public:
    int add(int n) {
        int sum = 0;
        while(n) {
            int k = n % 10;
            sum += k * k;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int num = 0;
        while(n != 1) {
            n = add(n); 
            num++;
            if (num > 730) return false;
        }
        return true;
    }
};


//方法二
class Solution {
private:
    map<int, int>m;
public:
    int add(int n) {
        int sum = 0;
        while(n) {
            int k = n % 10;
            sum += k * k;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        while(n != 1) {
            m[n]++;
            if (m[n] > 1) return false;
            n = add(n);
        }
        return true;
    }
};


//方法三
class Solution {
private:
    map<int, int>m;
public:
    int add(int n) {
        int sum = 0;
        while(n) {
            int k = n % 10;
            sum += k * k;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int p = n;
        int q = n;
        do {
            p = add(p);
            q = add(add(q));
        } while(p != q);
        return p == 1;
    }
};