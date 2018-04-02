//https://www.jiuzhang.com/solution/palindrome-linked-list/#tag-highlight-lang-cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head ->next == NULL) {
            return true;
        }
        ListNode* mid = findmid(head);
        mid->next = reverse(mid->next);
        mid = mid->next;
        while(head!=NULL && mid!=NULL) {
            if(head->val != mid->val) {
                return false;
            }
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode * findmid(ListNode * now) {
        ListNode* slow = now;
        ListNode* fast = now ->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode * reverse(ListNode *now) {
        ListNode * pre = NULL;
        while(now!=NULL) {
            ListNode *temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }
        return pre;
    }
};




//http://www.cnblogs.com/grandyang/p/4635425.html
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while (last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
