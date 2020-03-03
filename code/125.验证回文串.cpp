/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.43%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    81.6K
 * Total Submissions: 191.8K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        for (int b = 0, e = s.size() - 1; b < e; b++, e--)
        {
            while (!isalnum(s[b]) && b < e)
            {
                b++;
            }
            while (!isalnum(s[e]) && b < e)
            {
                e--;
            }
            if (toupper(s[b]) != toupper(s[e])){
                //不知道为什么toupper比tolower好
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

