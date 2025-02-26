/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.67%)
 * Likes:    7738
 * Dislikes: 0
 * Total Accepted:    851.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0)
            return res;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if (m.count(other) && m[other] != i)
            //防止重复使用，[3,2,4]&6 ->not [0, 0] but[1,2]
            {
                res.push_back(i);
                res.push_back(m[other]);
                return res;
            }
        }
        return res;
    }
        /* vector<int> res;
        if(nums.size()==0)
            return res;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    } */
       /*  unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            if(m.find(target-nums[i]) == m.end()){
                m[nums[i]] = i;
            }else{
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    } */
};
// @lc code=end

