/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.20%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    64.8K
 * Total Submissions: 124.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen = b.size();
        bool carry = false;
        string result;
        while(alen>0 || blen>0){
            int abit = alen <= 0 ? 0 : a[alen - 1] - '0';
            int bbit = blen <= 0 ? 0 : b[blen - 1] - '0';
            int cbit = carry ? 1 : 0;
            result.insert(result.begin(), '0' + ((abit + bbit + cbit) & 1));
            carry = (abit + bbit + cbit > 1);
            alen--;
            blen--;
        }
        if(carry){
            result.insert(result.begin(), '1');
        }
        return result;
    }
};
// @lc code=end

