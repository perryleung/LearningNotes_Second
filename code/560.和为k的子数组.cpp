/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.96%)
 * Likes:    741
 * Dislikes: 0
 * Total Accepted:    85.4K
 * Total Submissions: 190.2K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /* vector<int> preSum(nums.size() + 1, 0);
        for (int i = 0; i <= nums.size(); ++i) {
            preSum[i+1] = preSum[i] + nums[i];
        }
        int res = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j < i; ++j)
                if(preSum[i] - preSum[j] == k)
                    ++res;
        }
        return res; */
        int n = nums.size();
        //vector<int> preSum(n + 1, 0);
        unordered_map<int, int> mapped; //记录前缀和->前缀和出现的次数
        mapped[0] = 1;
        int res = 0;
        int sum_i = 0;
        for (int i = 0; i < n; ++i) {
            sum_i = sum_i + nums[i];
            int sum_j = sum_i - k;
            if (mapped.count(sum_j))
                res += mapped[sum_j];
            if (mapped.count(sum_i))
                mapped[sum_i] += 1;
            else
                mapped[sum_i] = 1;
            }
        return res;
    }
};
// @lc code=end

