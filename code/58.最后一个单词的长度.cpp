/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.47%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    70K
 * Total Submissions: 215.4K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
 * 
 * 如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include <cctype>

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(!s[0]){
            return 0;
        }
        int wordLen = 0;
        int cnt = 0;
        for (int i = 0; i<s.size(); i++)
        {
            if(isalpha(s[i])){
                cnt++;
            }
            if(!isalpha(s[i])){
                if(cnt>0){
                    wordLen = cnt;
                }
                cnt = 0;
            }
        }
        return cnt > 0 ? cnt : wordLen;
    }
};
// @lc code=end

