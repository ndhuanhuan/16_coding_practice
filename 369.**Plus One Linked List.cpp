
//http://www.cnblogs.com/grandyang/p/5626389.html

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if(!head) return head;
        int carry = helper(head);
        if(carry)
        {
            ListNode *res = new ListNode(1);
            res->next = head;
            return res;
        }
        return head;
    }
    
    int helper(ListNode* node)
    {
        if(!node) return 1;
        int carry = helper(node->next);
        int sum = node->val+carry;
        node->val = sum%10;
        return sum/10;
    }
    
    
};
