// https://leetcode.com/problems/toss-strange-coins/discuss/408518/C%2B%2B-DP-solution-with-intuitive-explanation
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<vector<double> > d(prob.size() + 1, vector<double>(target + 1, 0));
        d[0][0] = 1.0;
        for (int i = 1; i <= prob.size(); ++i)
            for (int j = 0; j <= target; ++j)
                if (j == 0) d[i][j] = d[i - 1][j] * (1 - prob[i - 1]);
                else  d[i][j] =  d[i - 1][j - 1] * prob[i - 1] + d[i - 1][j] * (1.0 - prob[i - 1]);
        return d[prob.size()][target];
    }
};
