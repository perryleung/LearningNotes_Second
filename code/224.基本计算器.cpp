/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode-cn.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (39.18%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 64.6K
 * Testcase Example:  '"1 + 1"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1 + 1"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
 * s 表示一个有效的表达式
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        char sign = '+';
        int num = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(isdigit(c))
                num = num * 10 + (c - '0');
            if(c == '(')
                num = calculate(s.substr(i + 1));
            if((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                switch(sign) {
                    case '+' :
                        stk.push(num);
                        break;
                    case '-' :
                        stk.push(-num);
                        break;  
                }
                sign = c;
                num = 0;
            }
            if(c == ')')
                break;        
        }
        int res = 0;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

