/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (63.73%)
 * Likes:    829
 * Dislikes: 0
 * Total Accepted:    123K
 * Total Submissions: 192.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* end) {
        /* if(!head)
            return nullptr;
        if(!head->next)
            return head; */
        /* ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *next = head->next;
        while(cur != end) { //左闭右开
            cur->next = pre;
            pre = cur;
            cur = next;
            next = cur->next;
        } */
        //要摒弃上述的写法，因为很容易溢出
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while(cur != end) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return nullptr;
        ListNode *front = head;
        ListNode *back = head;
        for (int i = 0; i < k; i++) {
            if (back == nullptr)
                return head;//注意这里是head而不是back
            back = back->next;
        }
        ListNode *newhead = reverse(front, back);
        front->next = reverseKGroup(back, k);
        return newhead;
    }
};
// @lc code=end

