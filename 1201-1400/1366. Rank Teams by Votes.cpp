// https://zxi.mytechroad.com/blog/simulation/leetcode-1366-rank-teams-by-votes/
class Solution {
public:
  string rankTeams(vector<string>& votes) {
    const int n = votes[0].length();
    string ans(votes[0]);
    vector<vector<int>> rank(26, vector<int>(n));
    
    for (const auto& vote : votes)
      for (int i = 0; i < n; ++i)
        ++rank[vote[i] - 'A'][i];
    
    sort(begin(ans), end(ans), [&](const char i, const char j) {
      if (rank[i - 'A'] != rank[j - 'A']) return rank[i - 'A'] > rank[j - 'A'];
      return i < j;
    });    
    return ans;
  }
};
