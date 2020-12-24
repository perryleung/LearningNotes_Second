/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (30.86%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    39.7K
 * Total Submissions: 126.6K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：k = 2, prices = [2,4,1]
 * 输出：2
 * 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：k = 2, prices = [3,2,6,5,0,3]
 * 输出：7
 * 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
 * ⁠    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 =
 * 3 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int n = prices.size();
        if (k > n / 2)
        {
            int dp_i_0 = 0;
            int dp_i_1 = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = max(dp_i_1, dp_i_0 - prices[i]);
            }
            return dp_i_0;
        }
        vector<vector<vector<int>>> dp(n, (k, (2, 0)));
        for (int i = 0; i < n; i++)
        {
            for (int j = k; j > 0; j++)
            {
                dp[i][j][0] = max(dp[i][j][0], dp[i][j - 1][1] + prices[i]);
                dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k - 1][0];
    }
};
// @lc code=end

