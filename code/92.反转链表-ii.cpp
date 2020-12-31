/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (51.81%)
 * Likes:    615
 * Dislikes: 0
 * Total Accepted:    92.4K
 * Total Submissions: 178K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode *successor = nullptr;
    ListNode* reverse(ListNode* head, int n) {
        if(n == 1) {
            successor = head->next;
            return head;
        }
        ListNode *plast = reverse(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return plast;//递归里面操作的只有head，没有plast，所以肯定是最后一个plast的
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1)
            return reverse(head, n);
        else 
            head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};
// @lc code=end

