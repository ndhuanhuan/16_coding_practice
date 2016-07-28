class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()||nums2.empty()) return {};
        unordered_map<int,int> map;
        vector<int> res;
        for(auto i:nums1)
        {
            map[i]++;
        }
        for(auto i:nums2)
        {
            if(map[i]>0)
            {
                res.push_back(i);
                map[i]--;
            }
            
        }
        return res;
        
    }
};


// If the given array is already sorted, and the memory is limited or m ~ n.
// Time:  O(m + n)
// Soace: O(1)
// Two pointers solution.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        // Make sure it is sorted, doesn't count in time.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                result.emplace_back(*it1);
                ++it1, ++it2;
            }
        }
        return result;
    }
};
