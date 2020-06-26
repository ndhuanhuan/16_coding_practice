// https://zxi.mytechroad.com/blog/hashtable/leetcode-1452-people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
class Solution {
public:
  vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    const int n = favoriteCompanies.size();
    vector<unordered_set<string>> m;
    for (const auto& c : favoriteCompanies)
      m.emplace_back(begin(c), end(c));
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      bool valid = true;
      for (int j = 0; j < n && valid; ++j) {
        if (i == j) continue;
        bool subset = true;
        for (const auto& s : m[i])
          if (!m[j].count(s)) {
            subset = false;
            break;
          }
        if (subset) {
          valid = false;
          break;
        }
      }
      if (valid) {
         ans.push_back(i);
      }
        
    }
    return ans;
  }
};
