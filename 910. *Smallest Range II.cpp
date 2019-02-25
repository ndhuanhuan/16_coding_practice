// https://zxi.mytechroad.com/blog/greedy/leetcode-910-smallest-range-ii/
// Explain: https://leetcode.com/problems/smallest-range-ii/solution/ 
// A[0] + K, A[i] + K, A[i+1] - K, A[A.length - 1] - K are the only relevant values for calculating the answer
class Solution {
public:
  int smallestRangeII(vector<int>& A, int K) {    
    sort(begin(A), end(A));    
    int ans = A.back() - A.front();
    for (int i = 1; i < A.size(); ++i) {      
      int l = min(A.front() + K, A[i] - K);
      int h = max(A.back() - K, A[i - 1] + K);
      ans = min(ans, h - l);
    }
    return ans;
  }
};
