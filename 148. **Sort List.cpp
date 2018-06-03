//http://www.cnblogs.com/grandyang/p/4249905.html
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};






//merge sort
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortList(head);
        slow = sortList(slow);
        return merge(fast, slow);
    }
    
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1) cur->next = head1;
        if (head2) cur->next = head2;
        return res->next;
    }
};
