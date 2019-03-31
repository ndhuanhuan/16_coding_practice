// https://www.youtube.com/watch?v=uFso48YRRao
// https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/265561/c%2B%2B-O(n)-using-stack
// stack saves index of number, stack need to maintain a decreasing stack. Once there's a larger number, we can update
// correspondant numbers in the ans array.
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
            ans.push_back(head->val);  //placeholder, it will be updated later.
            head = head->next;
        }
        
        while(!s.empty()){
            ans[s.top()] = 0;
            s.pop();
        }
        
        return ans;
    }
};
