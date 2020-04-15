// https://zxi.mytechroad.com/blog/sp/kmp-algorithm-sp19/
 namespace KMP {
    vector<int> Build(const string& p) {
      const int m = p.length();
      vector<int> nxt{0, 0};
      for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && p[i] != p[j])
          j = nxt[j];
        if (p[i] == p[j])
          ++j;
        nxt.push_back(j);
      }
      return nxt;
    }

    vector<int> Match(const string& s, const string& p) {
      vector<int> nxt(Build(p));
      vector<int> ans;
      const int n = s.length();
      const int m = p.length();
      for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j])
          j = nxt[j];
        if (s[i] == p[j])
          ++j;
        if (j == m) {
          ans.push_back(i - m + 1);
          j = nxt[j];
        }
      }
      return ans;
    }
    };  // namespace KMP


class Solution {
public:
   
    
    string longestPrefix(string s) {
        return s.substr(0, KMP::Build(s).back());
    }
};
