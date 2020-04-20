// https://zxi.mytechroad.com/blog/list/leetcode-725-split-linked-list-in-parts/
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        for (ListNode* head = root; head; head = head->next) ++len;
        vector<ListNode*> ans(k, nullptr);
        int l = len / k;
        int r = len % k;        
        ListNode* head = root;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; ++i, --r) {
            ans[i] = head;
            for (int j = 0; j < l + (r > 0); ++j) {
                prev = head;
                head = head->next;
            }
            if (prev) prev->next = nullptr;
        }
        return ans;
    }
};
