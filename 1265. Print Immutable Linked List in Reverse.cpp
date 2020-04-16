// https://leetcode.com/problems/print-immutable-linked-list-in-reverse/discuss/485903/Simple-recursive-C%2B%2B-or-3-Lines
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
      if(head==NULL) return;
      printLinkedListInReverse(head->getNext());
      head->printValue();
    }
};
