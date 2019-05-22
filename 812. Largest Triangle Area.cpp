// https://leetcode.com/problems/largest-triangle-area/discuss/122711/C%2B%2BJavaPython-Solution-with-Explanation-and-Prove
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double res = 0;
        for (auto &i : p)
            for (auto &j : p)
                for (auto &k : p)
            res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return res;
    }
};
