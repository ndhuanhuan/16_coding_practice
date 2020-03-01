// https://zxi.mytechroad.com/blog/searching/leetcode-1345-jump-game-iv/
class Solution {
public:
  int minJumps(vector<int>& arr) {
    const int n = arr.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i)
      m[arr[i]].push_back(i);
    vector<int> seen(n);
    queue<int> q({0});    
    seen[0] = 1;
    int steps = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int i = q.front(); q.pop();        
        if (i == n - 1) return steps;
        if (i - 1 >= 0 && !seen[i - 1]++) q.push(i - 1);
        if (i + 1 < n && !seen[i + 1]++) q.push(i + 1);
        auto it = m.find(arr[i]);
        if (it == m.end()) continue;
        for (int nxt : it->second)
          if (!seen[nxt]++) q.push(nxt);
        m.erase(it); // no longer needed.
      }
      ++steps;
    }
    return -1;
  }
};
