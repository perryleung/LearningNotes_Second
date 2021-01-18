/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 *
 * https://leetcode-cn.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 19.4K
 * Testcase Example:  '2\n[3]'
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：a = 2, b = [3]
 * 输出：8
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = 2, b = [1,0]
 * 输出：1024
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：a = 1, b = [4,3,3,8,5,2]
 * 输出：1
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：a = 2147483647, b = [2,0,0]
 * 输出：1198
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 0 
 * b 不含前导 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int base = 1337;
    int myPow(int a, int k) {
        int res = 1;
        a %= base;
        for (int i = 0; i < k; ++i) {
            res *= a;
            res %= base;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty())
            return 1;
        int back = b.back();
        b.pop_back();
        int part1 = myPow(a, back);//公式推导
        int part2 = myPow(superPow(a, b), 10);
        return (part1 * part2) % base;
    }
};
// @lc code=end

