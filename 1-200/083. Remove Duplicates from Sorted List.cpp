//http://www.cnblogs.com/grandyang/p/4066453.html
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *start = head;
        while (start && start->next) {
            if (start->val == start->next->val) {
                ListNode *tmp = start->next;
                start->next = start->next->next;
                delete tmp;
            } else start = start->next;
        }
        return head;
    }
};
