
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
       vector<vector<int>> res;
       map<int, vector<int>> m;
       for (auto& v : items) m[v[0]].push_back(v[1]);
       for (auto& [i, v] : m) {
          sort(v.begin(), v.end(), greater<int>());
          res.push_back({ i, (v[0] + v[1] + v[2] + v[3] + v[4]) / 5 });
       }
       return res;
    }
};
