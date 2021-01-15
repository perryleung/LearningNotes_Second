/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (43.39%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 97.5K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        for(char c : s)
            count[c]++;
        unordered_map<char, bool> check;
        stack<char> stackForChar;
        for(char c : s) {
            count[c]--;
            if(check.count(c) && check[c])
                continue;
            while(!stackForChar.empty() && stackForChar.top() > c) {
                if(count[stackForChar.top()] == 0)
                    break;
                if(count[stackForChar.top()] > 0) {
                    check[stackForChar.top()] = false;
                    stackForChar.pop();
                }
            }
            stackForChar.push(c);
            check[c] = true;
        }
        string res = "";
        while(!stackForChar.empty()) {
            res = res + stackForChar.top();
            stackForChar.pop();
        }
        reverse(res.begin(), res.end());//没有返回
        return res;
    }
};
// @lc code=end

