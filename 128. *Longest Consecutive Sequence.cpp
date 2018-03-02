//http://zxi.mytechroad.com/blog/hashtable/leetcode-128-longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums)            
            if (!h.count(num - 1)) {
                int l = 0;
                while (h.count(num++)) ++l;
                ans = max(ans, l);
            }
        return ans;
    }
};
