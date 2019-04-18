/*************************************************************************
	> File Name: Leetcode20.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 四  4/18 18:25:07 2019
 ************************************************************************/

//一个字符串只包含()[]{}六种符号，判断字符串是否闭合

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