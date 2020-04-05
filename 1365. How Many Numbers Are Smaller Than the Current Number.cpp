// https://zxi.mytechroad.com/blog/algorithms/array/%E8%8A%B1%E8%8A%B1%E9%85%B1-leetcode-1365-how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    const int n = nums.size();
    vector<int> s(nums);
    sort(begin(s), end(s));    
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
      ans[i] = distance(begin(s), lower_bound(begin(s), end(s), nums[i]));
    return ans;
  }
};
