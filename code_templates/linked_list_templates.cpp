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
