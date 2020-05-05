
// https://www.cnblogs.com/grandyang/p/10393508.html
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> cnt(n);
        for (int i = 1; i < n; ++i) {
            if (dominoes[i - 1] == 'R' && dominoes[i] == '.') {
                dominoes[i] = 'R';
                cnt[i] = cnt[i - 1] + 1;
            }
        }
        for (int i = n - 2, cur = 0; i >= 0; --i) {
            if (dominoes[i + 1] != 'L') continue;
            cur = cnt[i + 1] + 1;
            if (dominoes[i] == '.' || cnt[i] > cur) {
                dominoes[i] = 'L';
                cnt[i] = cur;
            } else if (dominoes[i] == 'R' && cnt[i] == cur) {
                dominoes[i] = '.';
            }
        }
        return dominoes;
    }
};


// https://zxi.mytechroad.com/blog/searching/leetcode-838-push-dominoes/
class Solution {
public:
  string pushDominoes(string D) {
    const int n = static_cast<int>(D.size());
    vector<int> L(n, INT_MAX), R(n, INT_MAX);    
    
    for (int i = 0; i < n; ++i)
      if (D[i] == 'L') {
        L[i] = 0;
        for (int j = i - 1; j >= 0 && D[j] == '.'; --j)
          L[j] = L[j + 1] + 1;
      } else if (D[i] == 'R') {        
        R[i] = 0;
        for (int j = i + 1; j < n && D[j] == '.'; ++j)
          R[j] = R[j - 1] + 1;
      }
    
    for (int i = 0; i < n; ++i)
      if (L[i] < R[i]) D[i] = 'L';
      else if (L[i] > R[i]) D[i] = 'R';
    
    return D;
  }
};
