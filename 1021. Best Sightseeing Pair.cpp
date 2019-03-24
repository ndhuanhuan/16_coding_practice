
// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-129-1020-1021-1022-1023/
class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& A) {
    int ans = 0;
    int left = 0;
    for (int i = 0; i < A.size(); ++i) {
      ans = max(ans, left + A[i] - i);
      left = max(left, A[i] + i);
    }
    return ans;
  }
};
