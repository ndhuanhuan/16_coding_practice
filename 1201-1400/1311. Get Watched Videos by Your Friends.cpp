// https://leetcode.com/problems/get-watched-videos-by-your-friends/discuss/470748/BFS-%2B-Hash-Map-%2B-Set
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
      unordered_set<int> visited = { id };
      vector<int> q1 = { id };
      vector<string> res;
      while (level-- > 0) {
        vector<int> q2;
        for (auto i : q1) {
          for (auto j : friends[i])
            if (visited.insert(j).second)
              q2.push_back(j);
        }
        swap(q1, q2);
      }
      unordered_map<string, int> freq;
      for (auto i : q1)
        for (auto& vid : watchedVideos[i])
          ++freq[vid];
      set<pair<int, string>> s;
      for (auto& p : freq)
        s.insert({ p.second, p.first });
      for (auto& p : s)
        res.push_back(p.second);
      return res;
    }
};
