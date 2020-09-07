/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (51.84%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    76.4K
 * Total Submissions: 147.4K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * num1 和num2 的长度都小于 5100
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int sum = 0;
        string res = "";
        while (i >= 0 || j >= 0 || sum) {
            if (i >= 0 && j >= 0) {
                sum += (num1[i--] - '0') + (num2[j--] - '0');
            }else if(i >= 0){
                sum += num1[i--] - '0';
            }else if(j >= 0){
                sum += num2[j--] - '0';
            }
            res += sum % 10 + '0';
            sum /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

