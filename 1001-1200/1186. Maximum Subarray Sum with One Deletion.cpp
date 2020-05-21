// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1186-maximum-subarray-sum-with-one-deletion/
class Solution {
public:
  int maximumSum(vector<int>& arr) {    
    int m = *max_element(begin(arr), end(arr));
    if (m <= 0) return m;
    
    int s0 = 0;
    int s1 = 0;
    int ans = 0;
    
    for (int a : arr) {
      s1 = max(s0, s1 + a);
      s0 += a;
      ans = max(ans, max(s0, s1));
      if (s0 < 0) s0 = 0;
      if (s1 < 0) s1 = 0;
    }
    
    return ans;
  }
};
