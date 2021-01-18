/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (76.01%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    126.1K
 * Total Submissions: 165.4K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        if(n < k || n < 1 || k < 1)
            return res;
        /* if(n == k) {
            for (i = 1; i <= k; ++i)
                path.push_back(i);
            res.push_back(path);
            return res;
        } */
        traceBack(1, n, k);
        return res;
    }
    void traceBack(int start, int n, int k) {
        if(path.size() == k)
            res.push_back(path);
        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            traceBack(i + 1, n, k);
            path.pop_back();
        }
    }
};
// @lc code=end

