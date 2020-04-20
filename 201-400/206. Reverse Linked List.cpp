class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* pre = NULL;
        while(head != NULL) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
	}
};



//http://www.cnblogs.com/grandyang/p/4478820.html
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = head;
        while (cur->next) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        return dummy->next;
    }
};
