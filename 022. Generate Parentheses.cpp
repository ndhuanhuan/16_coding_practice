//http://www.cnblogs.com/grandyang/p/4444160.html
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allComb;
        string comb;
        findParenthesis(n, 0, 0, comb, allComb);
        return allComb;
    }
    
    void findParenthesis(int n, int nleft, int nright, string &comb, vector<string> &allComb) {
        if(nleft==n && nright==n) {
            allComb.push_back(comb);
            return;
        }
        
        if(nleft<n) {
            comb.push_back('(');
            findParenthesis(n, nleft+1, nright, comb, allComb);
            comb.pop_back();
        }
        
        if(nright<nleft) {
            comb.push_back(')');
            findParenthesis(n, nleft, nright+1, comb, allComb);
            comb.pop_back();
        }
    }
};
