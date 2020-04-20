//http://www.cnblogs.com/grandyang/p/4370601.html
class Solution {
public:
    static bool comp(const Interval &a, const Interval &b) {
        return (a.start < b.start);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
