// https://zxi.mytechroad.com/blog/two-pointers/leetcode-1385-find-the-distance-value-between-two-arrays/
class Solution {
public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {    
    sort(begin(arr2), end(arr2));
    int ans = 0;
    for (int a : arr1) {
      auto it1 = lower_bound(begin(arr2), end(arr2), a - d);
      auto it2 = upper_bound(begin(arr2), end(arr2), a + d);
      if (it1 == it2) ++ans;
    }
    return ans;
  }
};
