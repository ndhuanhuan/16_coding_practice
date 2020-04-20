//https://zxi.mytechroad.com/blog/geometry/leetcode-986-interval-list-intersections/
class Solution {
public:
  vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
    size_t i = 0;
    size_t j = 0;
    vector<Interval> ans;
    while (i < A.size() && j < B.size()) {
      const int s = max(A[i].start, B[j].start);
      const int e = min(A[i].end, B[j].end);
      if (s <= e) ans.emplace_back(s, e);
      if (A[i].end < B[j].end)
        ++i;
      else
        ++j;
    }
    return ans;
  }
};
