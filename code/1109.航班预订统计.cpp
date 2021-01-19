/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 *
 * https://leetcode-cn.com/problems/corporate-flight-bookings/description/
 *
 * algorithms
 * Medium (49.12%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    18.7K
 * Total Submissions: 37.6K
 * Testcase Example:  '[[1,2,10],[2,3,20],[2,5,25]]\n5'
 *
 * 这里有 n 个航班，它们分别从 1 到 n 进行编号。
 * 
 * 我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [j, k, l] 意味着我们在从 j 到 k 的每个航班上预订了 l
 * 个座位。
 * 
 * 请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
 * 输出：[10,55,45,25,25]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < bookings.size(); ++i) {
            int j = bookings[i][0];
            int k = bookings[i][1];
            int l = bookings[i][2];
            diff[j - 1] += l;
            diff[k] -= l;
        }
        res[0] = diff[0];
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
// @lc code=end

