// https://zxi.mytechroad.com/blog/hashtable/leetcode-1394-find-lucky-integer-in-an-array/
class Solution {
public:
  int findLucky(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) ++freq[x];
    int ans = -1;
    for (const auto& [key, count] : freq)
      if (key == count) ans = max(ans, key);
    return ans;
  }
};
