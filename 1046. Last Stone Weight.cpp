class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> qu(stones.begin(),stones.end());
        
        while(qu.size() != 0 && qu.size() != 1){
            int temp1 = qu.top();
            qu.pop();
            int temp2 = qu.top();
            qu.pop();
            
            if(temp2 != temp1) qu.push(temp1 - temp2); 
        }
        
        if(!qu.size()) return 0;
        else return qu.top();
    }
};
