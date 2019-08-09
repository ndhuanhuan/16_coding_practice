// https://leetcode.com/problems/number-of-valid-subarrays/discuss/314317/C%2B%2B-O(n)-stack
class Solution {
public:
    int validSubarrays(vector<int>& nums, int res = 0) {
      vector<int> s;
      for (auto n : nums) {
        while (!s.empty() && n < s.back()) s.pop_back();
        s.push_back(n);
        res += s.size();
      }
      return res;
    }
};


input: [1,4,2,5,3]
calculate: 1 + 2 + 2 + 3 + 3 = 11

For example, number "3" (last element in array) can form [3], [1,3], [1,2,3]
