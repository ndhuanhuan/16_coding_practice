// Understand question: https://leetcode.com/problems/largest-values-from-labels/discuss/313011/Question-Explanation-and-Simple-Solution-or-Java-or-100
// https://leetcode.com/problems/largest-values-from-labels/discuss/312720/C%2B%2B-Greedy
class Solution {
public:
    int largestValsFromLabels(vector<int>& vs, vector<int>& ls, int wanted, int limit, int res = 0) {
      multimap<int, int> s;
      unordered_map<int, int> m;
      for (auto i = 0; i < vs.size(); ++i) s.insert({vs[i], ls[i]});
      for (auto it = rbegin(s); it != rend(s) && wanted > 0; ++it) {
        if (++m[it->second] <= limit) {
          res += it->first;
          --wanted;
        }
      }
      return res;
    }
};
