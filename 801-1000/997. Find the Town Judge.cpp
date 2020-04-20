class Solution {
public:
  int findJudge(int N, vector<vector<int>>& trusts) {    
    vector<int> degrees(N + 1);    
    for (const auto& trust : trusts) {
      --degrees[trust[0]];
      ++degrees[trust[1]];
    }
    for (int i = 1; i <= N; ++i)
      if (degrees[i] == N - 1) return i;
    return -1;
  }
};
