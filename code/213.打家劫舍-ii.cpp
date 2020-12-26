/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (40.09%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    68.5K
 * Total Submissions: 170.3K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int cur1 = 0;
        int cur2 = 0;
        int cur3 = 0;
        int pre = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int tmp = max(cur1, pre + nums[i]);
            pre = cur1;
            cur1 = tmp;
        }
        pre = 0;
        for (int i = 1; i < n; i++)
        {
            int tmp = max(cur2, pre + nums[i]);
            pre = cur2;
            cur2 = tmp;
        }
        /*  这种情况其实不需要，因为有前面两种情况的房子较多，每个房子的钱是非负的，因此房子多就是有更多的机会偷更多钱
        pre = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int tmp = max(cur3, pre + nums[i]);
            pre = cur3;
            cur3 = tmp;
        }
        */
        //int res = cur1 > cur2 ? cur1 : cur2;
        //res = res > cur3 ? res : cur3;
        return cur1 > cur2 ? cur1 : cur2;
    }
};
// @lc code=end

