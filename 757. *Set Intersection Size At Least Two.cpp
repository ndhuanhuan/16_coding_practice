// https://www.cnblogs.com/grandyang/p/8503476.html
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> v{-1, -1};
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        for (auto &interval : intervals) {
            int len = v.size();
            if (interval[0] <= v[len - 2]) continue; // 已经有两个相同的数字了，直接跳过当前区间
            if (interval[0] > v.back()) v.push_back(interval[1] - 1); // 二者没有任何交集
            v.push_back(interval[1]); // 不管区间和数组有一个交集还是没有任何交集，结束位置都要加入数组中
        }
        return v.size() - 2;
    }
};
