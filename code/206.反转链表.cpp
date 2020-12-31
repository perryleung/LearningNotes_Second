/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (71.08%)
 * Likes:    1414
 * Dislikes: 0
 * Total Accepted:    399.2K
 * Total Submissions: 560.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *next = head;
        while (cur->next != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        cur->next = pre;
        return cur;
    }
        /* if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode *p_last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p_last;
    } */
};
// @lc code=end

