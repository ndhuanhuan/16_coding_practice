//http://www.cnblogs.com/grandyang/p/5325761.html
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        return helper(pattern, 0, str, 0, m);
    }
    bool helper(string pattern, int p, string str, int r, unordered_map<char, string> &m) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i = r; i < str.size(); ++i) {
            string t = str.substr(r, i - r + 1);
            if (m.count(c) && m[c] == t) {
                if (helper(pattern, p + 1, str, i + 1, m)) return true;
            } else if (!m.count(c)) {
                bool b = false;
                for (auto it : m) {
                    if (it.second == t) b = true;
                } 
                if (!b) {
                    m[c] = t;
                    if (helper(pattern, p + 1, str, i + 1, m)) return true;
                    m.erase(c);
                }
            }
        }
        return false;
    }
};
