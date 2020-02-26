/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.54%)
 * Likes:    368
 * Dislikes: 0
 * Total Accepted:    132K
 * Total Submissions: 333.7K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
#include <time.h>
#include <stdlib.h>

class Solution {
public:
    Solution(){
        srand(time(NULL));
    }
    int strStr(string haystack, string needle) {
        if(random()%2){
            return strStr1(haystack, needle);
        }
        return strStr2(haystack, needle);
    }

    //KMP
    char *strStr1(char *haystack, char *needle){
        if(!haystack || !needle){
            return NULL;
        }
        if(!*needle){
            return haystack;
        }

        char *ph = haystack;
        char *pn = needle;
        for (; *ph && *pn; ph++,pn++)
            ;
        //len(haystack) < len(needle)
        if(!*ph && *pn){
            return NULL;
        }

        for (ph = ph - 1; *ph;haystack++,ph++){
            char *q = needle;
            char *p = haystack;
            int n = 0;
            while(*q && *p && *p==*q){
                p++;
                q++;
                if (n == 0 && *p == *needle){
                    n = p - haystack;
                }
            }
            if(!*q){
                return haystack;
            }
            haystack += (n > 0 ? n - 1 : n);
        }
        return NULL;
    }

    //brute-force
    char *strStr2(char *haystack, char *needle){
        if(!haystack || !needle){
            return NULL;
        }
        if(!*needle){
            return haystack;
        }

        char *ph = haystack;
        char *pn = needle;
        for (; *ph && *pn; ph++,pn++)
            ;
        //len(haystack) < len(needle)
        if(!*ph && *pn){
            return NULL;
        }

        ph--;
        for (; *ph;haystack++,ph++){
            char *q = needle;
            char *p = haystack;
            while(*q && *p && *p==*q){
                p++;
                q++;
            }
            if(!*q){
                return haystack;
            }
        }
        return NULL;
    }
};
// @lc code=end

