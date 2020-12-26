/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (49.01%)
 * Likes:    631
 * Dislikes: 0
 * Total Accepted:    92.5K
 * Total Submissions: 188.4K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false;
        sum = sum / 2;
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j != 0; j--) {
                if(j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
        /* vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));//dp[n+1][sum+1]
        for (int j = 0; j <= n; j++)
            dp[j][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j - nums[i - 1] < 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][sum]; */
    }
        /* int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 != 0)
            return false;
        int target = sum / 2;
        int n = nums.size();
        int dp_i = 0; //当i==0时，dp==0;
        for (int i = 0; i < n; i++) {
            if(dp_i + nums[i] > target)
                continue;
            dp_i = dp_i + nums[i];
            if(dp_i == target)
                return true;
        }
        return false;
    } */
};
// @lc code=end

