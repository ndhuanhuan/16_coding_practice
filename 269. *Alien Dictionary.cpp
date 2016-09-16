//http://www.cnblogs.com/grandyang/p/5250200.html
class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char> > s;
        unordered_set<char> ch;
        vector<int> in(256, 0);
        queue<char> q;
        string res = "";
        for (auto a : words) ch.insert(a.begin(), a.end());
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    s.insert(make_pair(words[i][j], words[i + 1][j]));  //characters sequence pairs
                    break;
                }
            }
        }
        for (auto a : s) ++in[a.second];
        for (auto a : ch) {          //if in degree is 0, it is the first character
            if (in[a] == 0) {
                q.push(a);
                res += a;
            } 
        }
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto a : s) {
                if (a.first == c) {
                    --in[a.second];
                    if (in[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";
    }
};
