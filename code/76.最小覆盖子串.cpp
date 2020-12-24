/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (39.82%)
 * Likes:    872
 * Dislikes: 0
 * Total Accepted:    96.2K
 * Total Submissions: 240.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;//其实window.size()==need.size()
        for(char c : t)
            need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        int start = left;
        int len = INT_MAX;
        while(right < s.size())
        {
            char c = s[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(window[c]==need[c])
                    valid++;//当找到一个字符的数量足够后，就valid++，后面再有也无所谓
            }
            while(valid == need.size())
            {
                if(right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if(need.count(d))
                {
                    if(window[d]==need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

