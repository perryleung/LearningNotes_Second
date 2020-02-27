/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (46.71%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    113.8K
 * Total Submissions: 243.1K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ia = m - 1;
        int ib = n - 1;
        int i = m + n - 1;
        for (int i = m + n - 1; i >= 0; i--){
            if (ia >= 0 && ib < 0){
                break;
            }
            if (ia < 0 && ib >= 0){
                nums1[i] = nums2[ib--];
                continue;
            }
            if (ia >= 0 && ib >= 0){
                if (nums1[ia] > nums2[ib]){
                    nums1[i] = nums1[ia--];
                }else{
                    nums1[i] = nums2[ib--];
                }
            }
        }
    }
};
// @lc code=end

