/*************************************************************************
	> File Name: Leetcode20.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 四  4/18 18:25:07 2019
 ************************************************************************/

//一个字符串只包含()[]{}六种符号，判断字符串是否闭合

//方法：使用一个栈来进行匹配操作

class Solution {
private:
    stack<char>sta;
public:
    bool isValid(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
            } else {
                if (sta.empty()) {
                    return false;
                }
                
                if (s[i] == ')') {
                    if (sta.top() != '(') {
                        return false;
                    }
                    sta.pop();
                } else if (s[i] == ']') {
                    if (sta.top() != '[') {
                        return false;
                    }
                    sta.pop();
                } else {
                    if (sta.top() != '{') {
                        return false;
                    }
                    sta.pop();
                }
            }
        }
        if (!sta.empty()) {
            return false;
        }
        
        return true;
    }
};


//方法二：利用模拟栈非递归
class Solution {
private:
    char *sta = (char *)malloc(sizeof(char) * 10005);
    int top = -1;
public:
    bool isValid(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta[++top] = s[i];
            } else {
                if (top == -1) {
                    return false;
                }
                
                if (s[i] == ')') {
                    if (sta[top] != '(') {
                        return false;
                    }
                } else if (s[i] == ']') {
                    if (sta[top] != '[') {
                        return false;
                    }
                } else {
                    if (sta[top] != '{') {
                        return false;
                    }
                }
                top --;
            }
        }
        if (top != -1) {
            return false;
        }
        
        return true;
    }
};
