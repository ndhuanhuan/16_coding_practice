// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-852-peak-index-in-a-mountain-array/
class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (A[m] > A[m + 1])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
