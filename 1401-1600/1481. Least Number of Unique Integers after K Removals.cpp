// https://zxi.mytechroad.com/blog/hashtable/leetcode-1481-least-number-of-unique-integers-after-k-removals/
class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {    
    unordered_map<int, int> c;
    for (int x : arr) ++c[x];
    vector<int> m; // freq
    for (const auto [x, f] : c)
      m.push_back(f);
    sort(begin(m), end(m));
    int ans = m.size();    
    int i = 0;
    while (k--) {
      if (--m[i] == 0) {
        ++i;
        --ans;
      }
    }
    return ans;
  }
};
