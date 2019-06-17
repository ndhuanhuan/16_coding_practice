// https://zxi.mytechroad.com/blog/hashtable/leetcode-760-find-anagram-mappings/
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, int> indices;
        for (int i = 0; i < B.size(); ++i)
            indices[B[i]] = i;
        vector<int> ans;
        for (const int a : A)
            ans.push_back(indices[a]);
        return ans;
    }
};
