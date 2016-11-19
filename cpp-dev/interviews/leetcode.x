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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        else if (l1 && !l2) return l1;
        else if (!l1 && l2) return l2;
        
        ListNode* head = NULL;
        ListNode* t1 = NULL;
        ListNode* t2 = NULL;
        ListNode* t = NULL;
        if (l1->val < l2->va1) {
            head = l1;
            t1 = head->next;
            t2 = l2;
        } else {
            head = l2;
            t1 = l1;
            t2 = head->next;
        }
        t = head;
        while (t1 || t2) {
            if (t1 && t2) {
                if (t1->val < t2->val) {
                    t->next = t1;
                    t1 = t1->next;
                    t = t->next;
                } else {
                    t->next = t2;
                    t2 = t2->next;
                    t = t->next;
                }
            } else if(t1) {
                t->next = t1;
                break;
            } else {
                t->next = t2;
                break;
            }
        }
        return head;
    }
};
