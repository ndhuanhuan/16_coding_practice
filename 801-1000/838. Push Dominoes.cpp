
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
