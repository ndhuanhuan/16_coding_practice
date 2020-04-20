class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        while(head)
        {
            ret <<= 1;
            ret |= head->val;
            head = head->next;
        }
        return ret;
    }
};
