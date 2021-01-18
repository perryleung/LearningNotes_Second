/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.52%)
 * Likes:    1514
 * Dislikes: 0
 * Total Accepted:    217.3K
 * Total Submissions: 283.3K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    string path;
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        traceBack(n, n);
        return res;
    }
    void traceBack(int left, int right) {
        if(left > right) //剩下的
            return;
        if(left < 0 || right < 0)
            return;
        if(left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        path.push_back('(');
        traceBack(left - 1, right);
        path.pop_back();
        path.push_back(')');
        traceBack(left, right - 1);
        path.pop_back();
    }
};
// @lc code=end

