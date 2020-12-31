/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (45.05%)
 * Likes:    805
 * Dislikes: 0
 * Total Accepted:    181.3K
 * Total Submissions: 401.7K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    ListNode* reverse(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    /* ListNode *left; */

    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        if (head->next == nullptr)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr)//说明链表是奇数个节点
            slow = slow->next;
        ListNode *p = reverse(slow);
        ListNode *q = head;
        while (p != nullptr) {
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
        /* left = head;
        return helper(head);
    } */
    /* bool helper(ListNode* head) {
        if(head == nullptr)
            return true;
        bool res = helper(head->next);
        res = res && (left->val == head->val);
        left = left->next;
        return res;
    } */
};
// @lc code=end

