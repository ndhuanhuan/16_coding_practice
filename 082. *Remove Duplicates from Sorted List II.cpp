//http://www.cnblogs.com/grandyang/p/4069003.html
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *pre = start;
        while (pre->next) {
            ListNode *cur = pre->next;
            while (cur->next && cur->next->val == cur->val) cur = cur->next;
            if (cur != pre->next) pre->next = cur->next; //this is compare pointer not the value. So if pre's next is not cur, which means cur has moved(Previously pre's next is cur), we need to delete some nodes.
            else pre = pre->next;
        }
        return start->next;
    }
};
