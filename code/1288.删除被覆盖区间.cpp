/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 *
 * https://leetcode-cn.com/problems/remove-covered-intervals/description/
 *
 * algorithms
 * Medium (54.83%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 10.9K
 * Testcase Example:  '[[1,4],[3,6],[2,8]]'
 *
 * 给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
 * 
 * 只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
 * 
 * 在完成所有删除操作后，请你返回列表中剩余区间的数目。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：intervals = [[1,4],[3,6],[2,8]]
 * 输出：2
 * 解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 * 
 * 
 * 
 * 
 * 提示：​​​​​​
 * 
 * 
 * 1 <= intervals.length <= 1000
 * 0 <= intervals[i][0] < intervals[i][1] <= 10^5
 * 对于所有的 i != j：intervals[i] != intervals[j]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0];
        int right = intervals[0][1];
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (left <= intervals[i][0] && right >= intervals[i][1])
            {
                res++;
            }
            if (right >= intervals[i][0] && right <= intervals[i][1])
            {
                right = intervals[i][1];
            }
            if(right < intervals[i][0])
            {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        return n - res;
    }
};
// @lc code=end

