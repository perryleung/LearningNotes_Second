/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (49.14%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    75.6K
 * Total Submissions: 153.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //暴力法
    /* ListNode* deleteDuplicates(ListNode* head) {
        for (ListNode *p = head; p && p->next;){
            if(p->val==p->next->val){
                p->next = p->next->next;
                continue;
            }
            p = p->next;
        }
        return head;
    } */
    //双指针
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast) {
            if(slow->val != fast->val) {
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};
// @lc code=end

