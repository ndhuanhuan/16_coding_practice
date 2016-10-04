//http://www.cnblogs.com/grandyang/p/4576240.html
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        string out;
        vector<bool> possible(s.size() + 1, true);
        wordBreakDFS(s, wordDict, 0, possible, out, res);
        return res;
    }
    void wordBreakDFS(string &s, unordered_set<string> &wordDict, int start, vector<bool> &possible, string &out, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(out.substr(0, out.size() - 1));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i - start + 1);
            if (wordDict.find(word) != wordDict.end() && possible[i + 1]) {
                out.append(word).append(" ");
                int oldSize = res.size();
                wordBreakDFS(s, wordDict, i + 1, possible, out, res);
                if (res.size() == oldSize) possible[i + 1] = false;
                out.resize(out.size() - word.size() - 1);
            }
        }
    }
};
