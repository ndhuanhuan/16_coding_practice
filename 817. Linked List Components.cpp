// https://zxi.mytechroad.com/blog/graph/leetcode-817-linked-list-components/
class Solution {
public:
  int numComponents(ListNode* head, vector<int>& G) {
    unordered_set<int> g(G.begin(), G.end());
    int ans = 0;
    while (head) {
      if (g.count(head->val) && (!head->next || !g.count(head->next->val)))
        ++ans;
      head = head->next;
    }
    return ans;
  }
};
