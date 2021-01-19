/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.55%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    121.1K
 * Total Submissions: 271.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 =="0" || num2 =="0")
            return "0"; //注意双引号是字符串
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = mul + res[p2];    //以防进位
                res[p2] = sum % 10;
                res[p1] += sum / 10;    //要注意
            }
        }
        int i = 0;
        while (i < res.size() && res[i] == 0)
            ++i;
        string res_str;
        for (; i < res.size(); ++i)
            res_str += '0' + res[i];    //单引号是字符
        return res_str;
        /* int m = num1.size() - 1, n = num2.size() - 1, carry = 0;
        string product;
        for (int i=0; i<=m+n || carry; ++i) {
            for (int j=max(0, i-n); j<=min(i, m); ++j)
                carry += (num1[m-j] - '0') * (num2[n-i+j] - '0');
            product += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(product), end(product));
        return product; */
    }
};
// @lc code=end

