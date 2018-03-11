/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    struct compNode
    {
        bool operator()(ListNode* l1, ListNode* l2) const
        {
            if (l1->val >= l2->val) 
			{
				return true;
			}
			else 
			{
				return false;
			}
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
		ListNode *dummy = new ListNode(0), *tail = dummy;
		for (int i = 0; i < lists.size(); i++) 
		{
			if (lists[i]) 
			{
				pq.push(lists[i]);
			}
			
		}
		while (!pq.empty()) {
			tail->next = pq.top();
			tail = tail->next;
			pq.pop();
			if (tail->next) pq.push(tail->next);
		}
		return dummy->next;

    }
};
