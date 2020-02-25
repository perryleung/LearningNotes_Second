/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.91%)
 * Likes:    1398
 * Dislikes: 0
 * Total Accepted:    208.7K
 * Total Submissions: 510.1K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch=='{' || ch=='[' || ch=='('){
                st.push(ch);
            }else if(ch=='}' || ch==']' || ch==')'){
                if(st.empty()){
                    return false;
                }else{
                    char sch = st.top();
                    if((sch=='{' && ch=='}') || (sch=='[' && ch==']') || (sch=='(' && ch==')')){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end

