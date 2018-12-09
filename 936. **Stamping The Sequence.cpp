//https://leetcode.com/problems/stamping-the-sequence/discuss/189502/C%2B%2BPython-12ms-Reverse-and-Greedy-O(N2M)
class Solution {
public:
    vector<int> movesToStamp(string s, string t) {
        int n = t.size(), m = s.size();
        
        auto check = [&](int i) {
            for (int j = 0; j < m; j++) {
                if (t[i + j] != '?' && t[i + j] != s[j]) return false;
            }
            for (int j = 0; j < m; j++) {
                if (t[i + j] != '?') return true;
            }
            return false;
        };
        
        vector<int> moves;
        string done(n, '?');
        
        while (t != done) {
            bool move = false;
            for (int i = 0; i < n - m + 1; i++) {
                if (check(i)) {
                    fill(t.begin() + i, t.begin() + i + m, '?');
                    moves.push_back(i);
                    move = true;
                }
            }
            if (!move) return {};
        }
        
        reverse(moves.begin(), moves.end());
        return moves;
    }
};




// https://zxi.mytechroad.com/blog/greedy/leetcode-936-stamping-the-sequence/
// Author: Huahua, running time: 12 ms
class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    vector<int> seen(target.length());
    int total = 0;
    while (total < target.length()) {      
      bool found = false;
      for (int i = 0; i <= target.length() - stamp.length(); ++i) {
        if (seen[i]) continue;
        int l = unStamp(stamp, target, i);
        if (l == 0) continue;
        seen[i] = 1;
        total += l;
        ans.push_back(i);
        found = true;
      }
      if (!found) return {};
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
private:
  int unStamp(const string& stamp, string& target, int s) {    
    int l = stamp.size();
    for (int i = 0; i < stamp.length(); ++i) {
      if (target[s + i] == '?')
        --l;
      else if (target[s + i] != stamp[i])
        return 0;
    }
    
    if (l != 0)
      std::fill(begin(target) + s, begin(target) + s + stamp.length(), '?');
    return l;
  }
};
