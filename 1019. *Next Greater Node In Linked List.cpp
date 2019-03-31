// https://www.youtube.com/watch?v=uFso48YRRao
// https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/265561/c%2B%2B-O(n)-using-stack
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        int idx = 0;
        
        while(head != NULL){
            while(!s.empty() && ans[s.top()] < head->val){
                ans[s.top()] = head->val;
                s.pop();
            }
            
            s.push(idx++);
            ans.push_back(head->val);
            head = head->next;
        }
        
        while(!s.empty()){
            ans[s.top()] = 0;
            s.pop();
        }
        
        return ans;
    }
};
