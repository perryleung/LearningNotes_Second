/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode-cn.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (58.27%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    39.9K
 * Total Submissions: 67.9K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x
 * 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数； 
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 注意: 输入数组的长度不会超过 10000。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, -1);
        stack<int> s;
        for (int i = 2 * size - 1; i >= 0; --i) {
            while (!s.empty() && nums[i % size] >= s.top())
                s.pop();
            res[i % size] = s.empty() ? -1 : s.top();
            s.push(nums[i % size]);
        }
        return res;
        /* int flag = 1;
        for (int i = 0; i < size; ++i) {
            int res_tmp = -1;
            int j = i + 1;
            for (; j < size; ++j) {
                if (nums[i] < nums[j]) {
                    res_tmp = nums[j];
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                for (j = 0; j < i; ++j) {
                    if (nums[i] < nums[j]) {
                        res_tmp = nums[j];
                        break;
                    }
                }
            }else {
                flag = 1;
            }
            res.push_back(res_tmp);
        }
        return res; */
    }
};
// @lc code=end

