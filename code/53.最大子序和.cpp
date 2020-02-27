/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.32%)
 * Likes:    1658
 * Dislikes: 0
 * Total Accepted:    166.3K
 * Total Submissions: 336.6K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start
#include <stdlib.h>
#include <vector>
#include <time.h>
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        if(random()%2)
            return maxSubArray1(nums);
        return maxSubArray2(nums);
    }

    int max(int x, int y){
        return x > y ? x : y;
    }

    //动态规划
    int maxSubArray1(vector<int>& nums){
        int n = nums.size();
        int *sum = new int[n];
        sum[0] = nums[0];
        int m = nums[0];
        for (int i = 1; i < n; i++){
            sum[i] = max(nums[i], sum[i - 1] + nums[i]);
            m = max(m, sum[i]);
        }
        delete[] sum;
        return m;
    }
    //贪心算法
    int maxSubArray2(vector<int>& nums){
        int m = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            m = max(sum, m);
            if(sum<0)
                sum = 0;
        }
        return m;
    }

};
// @lc code=end

