/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.06%)
 * Likes:    868
 * Dislikes: 0
 * Total Accepted:    90K
 * Total Submissions: 130.1K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 1;//??
        res[1] = 1;
        for (int i = 2; i <= n; i++){       //算G(n)
            for (int j = 1; j <= i; j++)    //算f(i)
                res[i] += res[j - 1] * res[i - j];
        }
        return res[n];
    }
};
// @lc code=end

