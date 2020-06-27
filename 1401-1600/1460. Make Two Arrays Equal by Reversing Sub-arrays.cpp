// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1460-make-two-arrays-equal-by-reversing-sub-arrays/
class Solution {
public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    vector<int> t(1001);
    vector<int> a(1001);
    for (int i = 0; i < target.size(); ++i) {
      ++t[target[i]];
      ++a[arr[i]];
    }
    return t == a;
  }
};
