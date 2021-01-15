/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (37.88%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    50.1K
 * Total Submissions: 131.7K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
 * 示例1:
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(char c : s1)
            need[c]++;
        int left = 0;
        int right = 0;
        int valid = 0;
        while(right < s2.size()) {
            char c_r = s2[right];
            right++;
            if(need.count(c_r)) {
                window[c_r]++;
                if(window[c_r] == need[c_r])
                    valid++;
            }
            if(right - left >= s1.size()) {
                if(valid == need.size())
                    return true;
                char c_l = s2[left];
                left++;
                if(need.count(c_l)) {
                    if(window[c_l] == need[c_l])
                        valid--;
                    window[c_l]--;
                }  
            }
        }
        return false;
    }
};
// @lc code=end

