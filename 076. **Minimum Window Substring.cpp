//http://www.cnblogs.com/grandyang/p/4340948.html
class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        unordered_map<char, int> m;
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }
        for (int right = 0; right < S.size(); ++right) {
            if (m.find(S[right]) != m.end()) {
                --m[S[right]];
                if (m[S[right]] >= 0) ++count;
                while (count == T.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (m.find(S[left]) != m.end()) {
                        ++m[S[left]];
                        if (m[S[left]] > 0) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};
