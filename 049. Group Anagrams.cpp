
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> rec;
    
        for (auto s : strs) {
            string key = s;
            sort(key.begin(),key.end());
            rec[key].push_back(s);
        }
    
        for (auto p : rec)
            ret.push_back(p.second);
    
        return ret;
    }
};
