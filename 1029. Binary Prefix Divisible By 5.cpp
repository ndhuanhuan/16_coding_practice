
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        
        long long cur = 0;
        for(auto i=0; i < A.size(); ++i) {
            cur = cur *2 + A[i];
            if(cur % 5 ==0) {
                res.push_back(true);
                
            } else {
                res.push_back(false);
            }
            cur = cur%5;
        }
        return res;
    }
};
