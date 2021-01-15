/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 *
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (53.87%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 16.2K
 * Testcase Example:  '"bcabc"'
 *
 * 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
 * 
 * 注意：该题与 316 https://leetcode.com/problems/remove-duplicate-letters/ 相同
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
    string smallestSubsequence(string s) {
        unordered_map<char, int> count;
        for(char c : s) {
            count[c]++;
        }
        unordered_map<char, bool> check;
        deque<char> q;
        for(char c : s) {
            count[c]--;
            if(check.count(c) && check[c])
                continue;
            while(!q.empty() && q.back() > c) {
                if(count[q.back()] == 0)
                    break;
                check[q.back()] = false;
                q.pop_back();
            }
            q.push_back(c);
            check[c] = true;
        }
        string res = "";
        while(!q.empty()) {
            res = res + q.front();
            q.pop_front();
        }
        return res;
    }
};
// @lc code=end

