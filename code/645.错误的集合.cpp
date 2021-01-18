/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 *
 * https://leetcode-cn.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (42.32%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 67.6K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 S 包含从 1 到 n
 * 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 进阶：你可以实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案吗？
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：nums = [1,2,2,4]
 * 输出：[2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 数组 nums 的长度范围是 [2, 10000] 。
 * 给定的数组是无序的。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
            else
                res.push_back(abs(nums[i]));
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {
                res.push_back(i + 1);
                break;
            }
        }
        return res;
    }
};
// @lc code=end

