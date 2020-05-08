// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-898-bitwise-ors-of-subarrays/
class Solution {
public:
  int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> ans;
    unordered_set<int> cur;
    unordered_set<int> nxt;
    for (int a : A) {
      nxt.clear();
      nxt.insert({a});
      for (int b : cur) {
        nxt.insert(a | b);
      }
      cur.swap(nxt);
      ans.insert(begin(cur), end(cur));
    }
    return ans.size();
  }
}
