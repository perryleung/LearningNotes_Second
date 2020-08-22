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
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 0; i < sqrt(n); i++){
            if(prime[i]){
                for (int j = i * i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};
// @lc code=end

