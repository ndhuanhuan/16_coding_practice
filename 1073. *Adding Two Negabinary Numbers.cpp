// https://leetcode.com/problems/adding-two-negabinary-numbers/discuss/303831/ChineseC%2B%2B-1073.
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        std::reverse(arr1.begin(), arr1.end());
        std::reverse(arr2.begin(), arr2.end());
        
        int maxSize = 5 + max(arr1.size(), arr2.size());
        vector<int> ans(maxSize, 0);
        
        arr1.resize(maxSize, 0);
        arr2.resize(maxSize, 0);
        
        for(int i=0;i<ans.size();i++){
            ans[i] = arr1[i] + arr2[i];
        }
        
        for(int i=0;i<ans.size();i++){
            while(ans[i] >= 2 && ans[i+1] > 0){
                ans[i] -= 2;
                ans[i+1]--;
            }
            
            while(ans[i] >= 2){
                ans[i] -= 2;
                ans[i+1]++;
                ans[i+2]++;
            }
        }
        
        while(ans.size()>1 && ans.back() == 0){
            ans.pop_back();
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
