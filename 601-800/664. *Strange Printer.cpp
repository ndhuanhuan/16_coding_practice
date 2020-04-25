// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-664-strange-printer/
class Solution {
public:
    int strangePrinter(const string& s) {
        int l = s.length();
        t_ = vector<vector<int>>(l, vector<int>(l, 0));
        return turn(s, 0, s.length() - 1);
    }
private:
    // Minimal turns to print s[i] to s[j] 
    int turn(const string& s, int i, int j) {
        // Empty string
        if (i > j) return 0;        
        // Solved
        if (t_[i][j] > 0) return t_[i][j];
        
        // Default behavior, print s[i] to s[j-1] and print s[j]
        int ans = turn(s, i, j-1) + 1;
        
        for (int k = i; k < j; ++k)
            if (s[k] == s[j])
                ans = min(ans, turn(s, i, k) + turn(s, k + 1, j - 1));
        
        return t_[i][j] = ans;
    }
    
    vector<vector<int>> t_;
    
};
