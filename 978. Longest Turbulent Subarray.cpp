//https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-978-longest-turbulent-subarray/
class Solution {
public:
  int maxTurbulenceSize(vector<int>& A) {
    vector<int> up(A.size(), 1);
    vector<int> down(A.size(), 1);
    int ans = 1;
    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1]) up[i] = down[i - 1] + 1;
      if (A[i] < A[i - 1]) down[i] = up[i - 1] + 1;
      ans = max(ans, max(up[i], down[i]));      
    }
    return ans;
  }
};
