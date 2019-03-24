class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A, int parts = 0) {
      auto total = accumulate(begin(A), end(A), 0);
      if (total % 3 != 0) return false;
      for (auto i = 0, sum = 0; i < A.size(); ++i) {
        sum += A[i];
        if (sum == total / 3) ++parts, sum = 0;
      }
      return parts >= 3;
    }
};
