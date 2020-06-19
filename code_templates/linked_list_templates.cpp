// check if there's a cycle
bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast) {
      if (!fast->next) return false;
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) return true;
    }
    return false;
  }






// two pointer template
ListNode* slow = head;
ListNode* fast = head;
/**
 * Change this condition to fit specific problem.
 * Attention: remember to avoid null-pointer error
 **/
while (slow && fast && fast->next) {
    slow = slow->next;          // move slow pointer one step each time
    fast = fast->next->next;    // move fast pointer two steps each time
    if (slow == fast) {         // change this condition to fit specific problem
        return true;
    }
}
return false;   // change return value to fit specific problem





// Reverse Linked List
ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;      
    ListNode *pre = NULL;
    while(head) {
        ListNode *t = head->next;
        head->next = pre;
        pre = head;
        head = t;
    }

    return pre;
}
