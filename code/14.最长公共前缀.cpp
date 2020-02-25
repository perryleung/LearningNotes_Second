/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.25%)
 * Likes:    891
 * Dislikes: 0
 * Total Accepted:    191.2K
 * Total Submissions: 527.6K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word;
        if(strs.size()<=0)
            return word;

        for (int i = 0; i <= strs[0].size();i++){
            string w = strs[0].substr(0, i);//从第0个开始取i个
            bool match = true;
            for (int j = 1; j < strs.size();j++){
                if(i>strs[j].size() || w != strs[j].substr(0,i)){
                    match = false;
                    break;
                }
            }
            if(!match){
                return word;
            }
            word = w;
        }
        return word;
    }
};
// @lc code=end

