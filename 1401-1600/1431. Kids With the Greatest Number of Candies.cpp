// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1431-kids-with-the-greatest-number-of-candies/
class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    const int threshold = *max_element(begin(candies), end(candies));
    vector<bool> ans(candies.size());
    for (int i = 0; i < candies.size(); ++i)
      ans[i] = (candies[i] + extraCandies) >= threshold;
    return ans;
  }
};
