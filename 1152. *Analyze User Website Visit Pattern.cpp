// https://leetcode.com/problems/analyze-user-website-visit-pattern/discuss/360216/C%2B%2B-11-lines
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> m;               
        for (int i = 0; i < username.size(); i++) m[username[i]][timestamp[i]] = website[i];
        map<vector<string>, int> counter;
        for (auto& [user, timeline] : m) {
            vector<string> v;
            for (auto& [time, site] : timeline) v.push_back(site);
            set<vector<string>> seqs;
            for (int k = 0; k < v.size(); k++) for (int j = 0; j < k; j++) for (int i = 0; i < j; i++)   seqs.insert({v[i], v[j], v[k]});
            for (auto& seq : seqs) counter[seq]++;
        }
        return max_element(counter.begin(), counter.end(), [](auto& p1, auto& p2) {return p1.second < p2.second || p1.second == p2.second && p1.first > p2.first; })->first;
    }
};
