// https://zxi.mytechroad.com/blog/two-pointers/leetcode-1537-get-the-maximum-score/
class Solution {
public:
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    constexpr int kMod = 1e9 + 7;
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    vector<long> dp1(n1 + 1); // max path sum ends with nums1[i-1]
    vector<long> dp2(n2 + 1); // max path sum ends with nums2[j-1]
    int i = 0;
    int j = 0;
    while (i < n1 || j < n2) {
      if (i < n1 && j < n2 && nums1[i] == nums2[j]) {
        // Same, two choices, pick the larger one.
        dp2[j + 1] = dp1[i + 1] = max(dp1[i], dp2[j]) + nums1[i];
        ++i; ++j;
      } else if (i < n1 && (j == n2 || nums1[i] < nums2[j])) {
        dp1[i + 1] = dp1[i] + nums1[i];
        ++i;
      } else if (j < n2 && (i == n1 || nums2[j] < nums1[i])) {        
        dp2[j + 1] = dp2[j] + nums2[j];
        ++j;
      }
    }    
    return max(dp1.back(), dp2.back()) % kMod;
  }
};
