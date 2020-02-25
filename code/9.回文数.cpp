/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (57.09%)
 * Likes:    949
 * Dislikes: 0
 * Total Accepted:    255.2K
 * Total Submissions: 447K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start
#include <climits>
class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome1(x);
        return isPalindrome2(x);
    }
    
    bool isPalindrome1(int x){
        if(x<0){
            return false;
        }
        int len(1);//找到x有多少位
        for (; (x / len) >= 10; len*=10)
            ;
        while(x!=0){
            int left = x / len;
            int right = x % 10;

            if(left!=right){
                return false;
            }

            x = (x % len) / 10;
            len /= 100;
        }
        return true;
    }

    bool isPalindrome2(int x){
        return (x >= 0 && x == reverse(x));
    }

private:
    int reverse(int x){
        int y(0);
        int n;
        while(x!=0){
            n = x % 10;
            if(y > INT_MAX / 10 - n){
                return x - 1;
            }
            y = y * 10 + n;
            x /= 10;
        }
        return y;
    }
};
// @lc code=end

