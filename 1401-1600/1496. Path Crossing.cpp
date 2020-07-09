// https://zxi.mytechroad.com/blog/hashtable/leetcode-1496-path-crossing/
class Solution {
public:
  bool isPathCrossing(string path) {
    unordered_set<int> s;
    int x = 0;
    int y = 0;
    s.insert(x * 10000 + y);
    for (char d : path) {
      if (d == 'N') ++y;
      else if (d == 'S') --y;
      else if (d == 'E') ++x;
      else if (d == 'W') --x;
      if (!s.insert(x * 10000 + y).second)
        return true;
    }
    return false;
  }
};
