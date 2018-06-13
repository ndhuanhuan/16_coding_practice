//http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/
class Solution {
public:
    int countPalindromicSubsequences(const string& S) {
        const int n = S.length();
        m_ = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return count(S, 0, S.length() - 1);
    }
private:
    static constexpr long kMod = 1000000007;
    long count(const string& S, int s, int e) {
        if (s > e) return 0;
        if (s == e) return 1;        
        if (m_[s][e] > 0) return m_[s][e];        
        
        long ans = 0;
        if (S[s] == S[e]) {
            int l = s + 1;
            int r = e - 1;
            while (l <= r && S[l] != S[s]) ++l;
            while (l <= r && S[r] != S[s]) --r;
            if (l > r)
                ans = count(S, s + 1, e - 1) * 2 + 2;
            else if (l == r)
                ans = count(S, s + 1, e - 1) * 2 + 1;
            else
                ans = count(S, s + 1, e - 1) * 2 
                    - count(S, l + 1, r - 1);
        } else {
            ans = count(S, s, e - 1)
                + count(S, s + 1, e)
                - count(S, s + 1, e - 1);
        }
        
        return m_[s][e] = (ans + kMod) % kMod;
    }
    
    
    vector<vector<int>> m_;
};
