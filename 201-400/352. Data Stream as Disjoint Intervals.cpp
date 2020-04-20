//http://www.cnblogs.com/grandyang/p/5548284.html
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        Interval cur(val, val);
        vector<Interval> res;
        int pos = 0;
        for (auto a : v) {
            if (cur.end + 1 < a.start) {
                res.push_back(a);
            } else if (cur.start > a.end + 1) {
                res.push_back(a);
                ++pos;
            } else {
                cur.start = min(cur.start, a.start);
                cur.end = max(cur.end, a.end);
            }
        }
        res.insert(res.begin() + pos, cur);
        v = res;
    }
    
    vector<Interval> getIntervals() {
        return v;    
    }
    
private:
    vector<Interval> v;
};
