/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (34.92%)
 * Likes:    421
 * Dislikes: 0
 * Total Accepted:    72.8K
 * Total Submissions: 208.4K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> res(n, true);
        for (int i = 2; i * i < n; ++i) {
            if(isPrime(i))
                for (int j = 2 * i; j < n; j += i)
                    res[j] = false;
        }
        int count = 0;
        for (int i = 2; i < n; ++i) 
            if(res[i])
                ++count;
        return count;
    }
    bool isPrime(int n) {
        for (int i = 2; i * i < n; ++i) {
            if(n % i == 0)
                return false;
        }
        return true;
    }
        /* int res = 0;
        for (int i = 2; i < n; i++) {
            if(isPrimes(i))
                res++;
        }
        return res; */
        /* vector<bool> res(n, true);
        for (int i = 2; i * i < n; i++) {//将i<n优化成i*i<n
            if(isPrimes(i))
                for (int j = i * i; j < n; j += i)//将j=2*i优化成j=i*i, 但是个人觉得这里j = 2 * i 更好
                    res[j] = false;
        }
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if(res[i])
                count++;
        }
        return count;
    }
    bool isPrimes(int n) {
        for (int i = 2; i * i <= n; i++) {
            if(n % i == 0)
                return false;
        }
        return true;
    } */
};
// @lc code=end

