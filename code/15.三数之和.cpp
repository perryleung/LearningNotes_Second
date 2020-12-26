/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (30.19%)
 * Likes:    2837
 * Dislikes: 0
 * Total Accepted:    386.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while(front < back) {
                if(nums[front] + nums[back] < target)
                    front++;
                else if(nums[front] + nums[back] > target)
                    back--;
                else {
                    vector<int> tmp(3,0);
                    tmp[0] = nums[i];
                    tmp[1] = nums[front];
                    tmp[2] = nums[back];
                    res.push_back(tmp);
                    while(front < back && tmp[1 ]== nums[front])
                        front++;
                    while(front < back && tmp[2] == nums[back])
                        back--;
                }
           }
           //下面这里需要注意
           while(i+1 < nums.size() && nums[i+1]==nums[i])
               i++;
        }
        return res;
    }
};
// @lc code=end

