// https://zxi.mytechroad.com/blog/simulation/leetcode-1389-create-target-array-in-the-given-order/
class Solution {
public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> target;
    for (int i = 0; i < nums.size(); ++i)
      target.insert(begin(target) + index[i], nums[i]);
    return target;
  }
};
