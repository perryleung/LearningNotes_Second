/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (60.08%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    40.7K
 * Total Submissions: 67.7K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex + 1, 0);
        vec[0] = 1;
        for (int i = 0; i <= rowIndex; i++){
            for (int j = i; j > 0; j--){
                vec[j] += vec[j - 1];
            }
        }
        return vec;
    }
};
// @lc code=end

