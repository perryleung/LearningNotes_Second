/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (36.86%)
 * Likes:    372
 * Dislikes: 0
 * Total Accepted:    41K
 * Total Submissions: 110.8K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ret;
        sort(nums.begin(), nums.end(), [](const int &m, const int &n) { return to_string(m) + to_string(n) > to_string(n) + to_string(m); });
        for (int i = 0; i < nums.size(); ++i){
            ret += to_string(nums[i]);
        }
        if(ret[0]=='0'){
            return "0";
        }
        return ret;
    }
};
// @lc code=end

