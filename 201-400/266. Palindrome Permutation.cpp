//http://www.cnblogs.com/grandyang/p/5223238.html
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int cnt = 0;
        for (auto a : s) ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2) ++cnt;
        }
        return cnt == 0 || (s.size() % 2 == 1 && cnt == 1);
    }
};
