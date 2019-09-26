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
      s1 = max(s0, s1 + a); // s0 +. sum of previous without current(can be a sequence not starting from index 0), guarantee you can only drop one element
      s0 += a;
      ans = max(ans, max(s0, s1));
       // cout << "s0 " << s0 << endl;
       // cout << "s1 " << s1 << endl;
      if (s0 < 0) s0 = 0;
      if (s1 < 0) s1 = 0;
    }
    
    return ans;
  }
};
