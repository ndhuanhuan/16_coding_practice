class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
      short a[1001] = {}, i = 0;
      for (auto n : A) ++a[n];
      for (i = 1000; i >= 0 && a[i] != 1; --i);
      return i;
    }
};
