//http://www.cnblogs.com/grandyang/p/4250107.html
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        while (head) {
            ListNode *next = head->next;
            cur = res;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = next;
        }
        return res->next;
    }
};
