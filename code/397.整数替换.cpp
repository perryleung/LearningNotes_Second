/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 *
 * https://leetcode-cn.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (36.04%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 23.7K
 * Testcase Example:  '8'
 *
 * 给定一个正整数 n，你可以做如下操作：
 * 
 * 1. 如果 n 是偶数，则用 n / 2替换 n。
 * 2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
 * n 变为 1 所需的最小替换次数是多少？
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 8
 * 
 * 输出:
 * 3
 * 
 * 解释:
 * 8 -> 4 -> 2 -> 1
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * 7
 * 
 * 输出:
 * 4
 * 
 * 解释:
 * 7 -> 8 -> 4 -> 2 -> 1
 * 或
 * 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        int c = 0;
        int i = n;
        while(i!=1){
            if (i % 2 == 0){
                i /= 2;    
            }else{
                if ((i - 1) % 2 == 0 || (i - 1) / 2 == 1)
                {
                    i--;
                }
                else
                {
                    i++;
                }
            }
            c++;
        }
        return c;
    }
};
// @lc code=end

