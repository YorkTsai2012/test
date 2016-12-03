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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return NULL;
        } else if (!l1 && l2) {
            return l2;
        } else if (l1 && !l2) {
            return l1;
        }
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int curval = ( t1->val + t2->val) % 10;
        int extra = (t1->val + t2->val) / 10;
        ListNode* head = new ListNode(curval);
        ListNode* master = head;
        t1 = t1->next;
        t2 = t2->next;
       
        while (t1 || t2) {
            int x = t1? t1->val: 0;
            int y = t2? t2->val: 0;
            curval = (x + y + extra) % 10;
            extra = (x + y + extra) / 10;
            master->next = new ListNode(curval);
            master = master->next;
            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }
        if (extra > 0) {
            master->next = new ListNode(extra);
        }
        return head;
    }
};



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return NULL;
        } else if (!l1 && l2) {
            return l2;
        } else if (l1 && !l2) {
            return l1;
        }
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int extra = 0;
        int curval = 0;
        if (t1->val + t2->val > 9) {
            curval = t1->val + t2->val - 10;
            extra = 1;
        } else {
            curval = t1->val + t2->val;
            extra = 0;
        }
        ListNode* head = new ListNode(curval);
        ListNode* master = head;
        t1 = t1->next;
        t2 = t2->next;
       
        while (t1 || t2) {
            if (t1 && t2) {
                if (t1->val + t2->val + extra > 9) {
                    curval = t1->val + t2->val + extra - 10;
                    extra = 1;
                } else {
                    curval = t1->val + t2->val + extra;
                    extra = 0;
                }
                master->next = new ListNode(curval);
                master = master->next;
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1) {
                if (t1->val + extra  > 9) {
                    curval = t1->val + extra - 10;
                    extra = 1;
                } else {
                    curval = t1->val + extra;
                    extra = 0;
                }
                master->next = new ListNode(curval);
                master = master->next;
                t1 = t1->next;
            } else {
                if (t2->val + extra > 9) {
                    curval = t2->val + extra - 10;
                    extra = 1;
                } else {
                    curval = t2->val + extra;
                    extra = 0;
                }
                master->next = new ListNode(curval);
                master = master->next;
                t2 = t2->next;
            }
        }
        if (extra > 0) {
            master->next = new ListNode(extra);
        }
        return head;
    }
};
