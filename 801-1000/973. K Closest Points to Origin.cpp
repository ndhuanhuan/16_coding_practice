






class Comp {
    public:
        bool operator()(std::pair<int, std::vector<int>> p1, std::pair<int, std::vector<int>> p2) {
            return p1.first < p2.first;
        }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::priority_queue<std::pair<int, std::vector<int>>, 
                            std::vector<std::pair<int, std::vector<int>>>, Comp> q;
        for (int i = 0; i < points.size(); i++) {
            q.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], points[i]});
            if (q.size() > K) q.pop();
        }
        std::vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};


class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {    
    vector<long> s(points.size());
    for (int i = 0; i < points.size(); ++i)
      s[i] = (static_cast<long>(points[i][0] * points[i][0] + 
                                points[i][1] * points[i][1]) << 32) | i;
    std::sort(begin(s), end(s));
    
    vector<vector<int>> ans(K);
    for (int i = 0; i < K; ++i)
      ans[i] = points[static_cast<int>(s[i])];
    return ans;
  }
};
