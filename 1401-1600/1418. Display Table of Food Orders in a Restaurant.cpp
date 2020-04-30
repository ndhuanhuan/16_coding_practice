// https://zxi.mytechroad.com/blog/hashtable/leetcode-1419-minimum-number-of-frogs-croaking/
class Solution {
public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    map<int, unordered_map<string, int>> tables;
    set<string> foods;
    for (const auto& order : orders) {
      ++tables[stoi(order[1])][order[2]];
      foods.insert(order[2]);
    }
    vector<vector<string>> ans;
    ans.push_back({{"Table"}});    
    ans.back().insert(end(ans.back()), begin(foods), end(foods));
    for (auto& [table, m] : tables) {
      vector<string> line{to_string(table)};
      for (const auto& food : foods)
        line.push_back(to_string(m[food]));
      ans.push_back(move(line));
    }
    return ans;
  }
};
