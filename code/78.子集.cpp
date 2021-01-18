/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.30%)
 * Likes:    948
 * Dislikes: 0
 * Total Accepted:    186.4K
 * Total Submissions: 234.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path = {};
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0)
            return res;
        traceBack(nums, 0, path);
        return res;
    }
    void traceBack(const vector<int> & nums, int start, vector<int> path) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            traceBack(nums, i + 1, path);
            path.pop_back();
        }
    }
};
// @lc code=end

