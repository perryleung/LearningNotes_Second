/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 *
 * https://leetcode-cn.com/problems/random-pick-with-blacklist/description/
 *
 * algorithms
 * Hard (32.51%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 8.1K
 * Testcase Example:  '["Solution", "pick", "pick", "pick"]\n[[1, []], [], [], []]'
 *
 * 给定一个包含 [0，n ) 中独特的整数的黑名单 B，写一个函数从 [ 0，n ) 中返回一个不在 B 中的随机整数。
 * 
 * 对它进行优化使其尽量少调用系统方法 Math.random() 。
 * 
 * 提示:
 * 
 * 
 * 1 <= N <= 1000000000
 * 0 <= B.length < min(100000, N)
 * [0, N) 不包含 N，详细参见 interval notation 。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ["Solution","pick","pick","pick"]
 * [[1,[]],[],[],[]]
 * 输出: [null,0,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ["Solution","pick","pick","pick"]
 * [[2,[]],[],[],[]]
 * 输出: [null,1,1,1]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 
 * ["Solution","pick","pick","pick"]
 * [[3,[1]],[],[],[]]
 * Output: [null,0,0,2]
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: 
 * ["Solution","pick","pick","pick"]
 * [[4,[2]],[],[],[]]
 * 输出: [null,1,3,1]
 * 
 * 
 * 输入语法说明：
 * 
 * 输入是两个列表：调用成员函数名和调用的参数。Solution的构造函数有两个参数，N 和黑名单 B。pick
 * 没有参数，输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。
 * 
 */

// @lc code=start
class Solution {
private:
    int sz;
    unordered_map<int, int> mapping;

public:
    Solution(int N, vector<int>& blacklist) {
        sz = N - blacklist.size();
        for(int b : blacklist)
            mapping[b] = N;
        int last = N - 1;   //开始找映射，从倒数的第一个不在BL中的数字开始
        for(int b : blacklist) {
            //开始遍历黑名单
            //在每次处理黑名单中的元素时，先找它映射的位置
            while(mapping.count(last))//如果映射的位置也是在黑名单中
                last--;//往前
            if(b >= sz)//如果在末尾位置，直接跳过不处理
                continue;
            mapping[b] = last;
            last--;
        }
    }
    int pick() {
        int num = rand() % sz;
        if(mapping.count(num))
            return mapping[num];
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

