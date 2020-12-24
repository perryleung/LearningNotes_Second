/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.25%)
 * Likes:    1041
 * Dislikes: 0
 * Total Accepted:    230.8K
 * Total Submissions: 298.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() < 1)
            return res;
        vector<bool> used(nums.size(), false);
        helper(nums, used);
        return res;
    }

    void helper(vector<int>& nums, vector<bool>& used)
    {
        if (nums.size() == path.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            helper(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

