// https://zxi.mytechroad.com/blog/hashtable/leetcode-734-sentence-similarity/
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        unordered_map<string, unordered_set<string>> similar_words;
        for (const auto& pair : pairs) {            
            similar_words[pair[0]].insert(pair[1]);
            similar_words[pair[1]].insert(pair[0]);
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (!similar_words[words1[i]].count(words2[i])) return false;
        }
        
        return true;
    }
};
