
class Solution {
public:
  vector<string> uncommonFromSentences(string A, string B) {
    istringstream ss(A + " " + B);
    unordered_map<string, int> counts;
    string s;
    while (ss >> s) ++counts[s];
    vector<string> ans;
    for (const auto& p : counts)
      if (p.second == 1)
        ans.push_back(p.first);
    return ans;
  }
};
