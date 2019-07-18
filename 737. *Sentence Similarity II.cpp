

// https://zxi.mytechroad.com/blog/hashtable/leetcode-737-sentence-similarity-ii/

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        g_.clear();
        ids_.clear();
        
        for (const auto& p : pairs) {
            g_[p[0]].insert(p[1]);
            g_[p[1]].insert(p[0]);
        }        
        
        int id = 0;
        
        for (const auto& p : pairs) {
            if(!ids_.count(p[0])) dfs(p[0], ++id); //assign id to strings
            if(!ids_.count(p[1])) dfs(p[1], ++id); //assign id to strings
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            auto it1 = ids_.find(words1[i]);
            auto it2 = ids_.find(words2[i]);
            if (it1 == ids_.end() || it2 == ids_.end()) return false;
            if (it1->second != it2->second) return false;
        }
        
        return true;
    }
private:
    bool dfs(const string& curr, int id) {
        ids_[curr] = id;        
        for (const auto& next : g_[curr]) {
            if (ids_.count(next)) continue;
            if (dfs(next, id)) return true;
        }
        return false;
    }
    
    unordered_map<string, int> ids_;
    unordered_map<string, unordered_set<string>> g_;
};
