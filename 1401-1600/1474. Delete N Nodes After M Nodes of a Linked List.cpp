
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* temp = head;
        while(temp){
            for(int i = 0; i < m - 1 && temp; i++){
                temp = temp->next;
            }
            if(!temp) break;
            ListNode* jump = temp;
            for(int i = 0; i < n + 1 && jump; i++){
                jump = jump->next;
            }
            if(!jump) {
                temp->next = NULL;
                break;
            }
            temp->next = jump;
            temp = jump;           
        }
        return head;
    }
};
