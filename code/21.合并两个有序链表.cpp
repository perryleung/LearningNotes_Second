/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (59.83%)
 * Likes:    864
 * Dislikes: 0
 * Total Accepted:    187.9K
 * Total Submissions: 313.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
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
#include <time.h>
#include <stdlib.h>
/*
struct ListNode{
    int val;
    ListNode *next;
};
*/
class Solution {
public:
    Solution(){
        srand(time(NULL));
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        switch (random()%3)
        {
        case 0:
            return mergeTwoLists0(l1, l2);
        case 1:
            return mergeTwoLists1(l1, l2);
        default:
            return mergeTwoLists2(l1, l2);
        }
    }

    /*merge the 2nd list into 1st list*/
    ListNode* mergeTwoLists0(ListNode* head1, ListNode* head2){
        ListNode *p1 = head1, *p2 = head2;
        static ListNode dummy(0);
        
        dummy.next = p1;
        ListNode *prev = &dummy;
        
        while(p1 && p2){
            if(p1->val < p2->val){
                prev = p1;
                p1 = p1->next;
            }else{
                prev->next = p2;
                p2 = p2->next;
                prev = prev->next;
                prev->next = p1;
            }
        }
        if(p2){
            prev->next = p2;
        }
        return dummy.next;
    }

    /*merge two lists to the new list*/
    ListNode *mergeTwoLists1(ListNode *l1,ListNode *l2){
        ListNode *l = NULL, *p = NULL;

        while(l1!=NULL && l2 !=NULL){
            ListNode *n = NULL;
            if(l1->val < l2->val){
                n = l1;
                l1 = l1->next;
            }else{
                n = l2;
                l2 = l2->next;
            }
            if(l==NULL){
                l = p = n;
            }else{
                p->next = n;
                p = p->next;
            }
        }

        ListNode *rest = l1 ? l1 : l2;
        l = mergeTheRest(rest, l, p);
        return l;
    }
    ListNode* mergeTheRest(ListNode *l, ListNode *head, ListNode *tail){
        if(l){
            if(head && tail){
                tail->next = l;
            }else{
                head = l;
            }
        }
        return head;
    }

    /*pointer to pointer*/
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2){
        ListNode *head = NULL;
        ListNode **pTail = &head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                *pTail = l1;
                l1 = l1->next;
            }else{
                *pTail = l2;
                l2 = l2->next;
            }
            pTail = &(*pTail)->next;
        }
        *pTail = (l1 != NULL ? l1 : l2);
        return head;
    }
};
// @lc code=end

