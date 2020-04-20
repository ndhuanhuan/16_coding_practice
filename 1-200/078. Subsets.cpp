//http://bangbingsyb.blogspot.com/2014/11/leetcode-subsets-i-ii.html
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> allSets;
        vector<int> sol;
        allSets.push_back(sol);
        sort(S.begin(),S.end());
        findSubsets(S, 0, sol, allSets);
        return allSets;
    }
    
    void findSubsets(vector<int> &S, int start, vector<int> &sol, vector<vector<int>> &allSets) {
        for(int i=start; i<S.size(); i++) {
            sol.push_back(S[i]);
            allSets.push_back(sol);
            findSubsets(S, i+1, sol, allSets);
            sol.pop_back();
        }
    }
};
