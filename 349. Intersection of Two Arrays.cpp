class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()||nums2.empty()) return {};
        unordered_map<int,bool> map;
        vector<int> res;
        for(auto i:nums1)
        {
            map[i] = true;
        }
        for(auto i:nums2)
        {
            if(map[i])
            {
                res.push_back(i);
                map[i]=false;
            }
            
        }
        return res;
        
    }
};
