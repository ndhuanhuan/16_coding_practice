// https://www.hrwhisper.me/leetcode-linklist/
ListNode *reverse(ListNode *head){
        if(!head) return head;
        ListNode *p = head->next;
        ListNode *new_head = head;
        while(p){
            head->next = p->next;
            p->next = new_head;
            new_head = p;
            p = head->next;
        }
        return new_head;
    }
