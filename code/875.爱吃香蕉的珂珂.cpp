/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 *
 * https://leetcode-cn.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (45.60%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 52.4K
 * Testcase Example:  '[3,6,7,11]\r\n8\r'
 *
 * 珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。
 * 
 * 珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K
 * 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
 * 
 * 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
 * 
 * 返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: piles = [3,6,7,11], H = 8
 * 输出: 4
 * 
 * 
 * 示例 2：
 * 
 * 输入: piles = [30,11,23,4,20], H = 5
 * 输出: 30
 * 
 * 
 * 示例 3：
 * 
 * 输入: piles = [30,11,23,4,20], H = 6
 * 输出: 23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= H <= 10^9
 * 1 <= piles[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long sum = 0;
        int mx = 0;
        for(int pile : piles) {
            sum += pile;
            mx = max(mx, pile);
        }
        int l = sum / H;
        int r = mx;
        int res = 0;
        while(l < r) {
            int mid = l + 0.5 * (r - l);
            res = finishTime(piles, mid);
            if(res <= H) // 二分法找最左边边界
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    int finishTime(const vector<int>& piles, int speed) {
        int time = 0;
        if(speed == 0)//attention！！！
            return INT_MAX;
        for(int pile : piles) {
            time += ((pile / speed) + ((pile % speed > 0) ? 1 : 0));
        }
        return time;
    } 
       /*  int speed = 1;
        int maxSpeed = getMax(piles);
        for (; speed <= maxSpeed; ++speed) {
            if(canFinish(piles, speed, H))
                return speed;
        }
        return speed;
    }
    int getMax(const vector<int>& piles) {
        int size = piles.size();
        int res = piles[0];
        for (int i = 1; i < size; ++i) {
            if(piles[i] > res)
                res = piles[i];
        }
        return res;
    }
    bool canFinish(const vector<int>& piles, int speed, int H) {
        int time = 0;
        for(int pile : piles) {
            time += ((pile / speed) + ((pile % speed > 0) ? 1 : 0));
        }
        return time <= H;
    } */
};
// @lc code=end

