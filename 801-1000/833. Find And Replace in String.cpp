
// https://leetcode.com/problems/find-and-replace-in-string/discuss/130587/C%2B%2BJavaPython-Replace-S-from-right-to-left
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sorted;
        for (int i = 0 ; i < indexes.size(); i++) sorted.push_back(make_pair(indexes[i], i));
        sort(sorted.rbegin(), sorted.rend());
        for (auto ind : sorted) {
            int i = ind.first;
            string s = sources[ind.second], t = targets[ind.second];
            if (S.substr(i, s.length()) == s) S = S.substr(0, i) + t + S.substr(i + s.length());
        }
        return S;
    }
};
