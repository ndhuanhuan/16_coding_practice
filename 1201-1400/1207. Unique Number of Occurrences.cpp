// https://zxi.mytechroad.com/blog/hashtable/leecode-1207-unique-number-of-occurrences/
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> c;
    for (int a : arr) ++c[a];
    unordered_set<int> s;
    for (const auto& kv : c)
      if (!s.insert(kv.second).second) 
        return false;
    return true;
  }
};
