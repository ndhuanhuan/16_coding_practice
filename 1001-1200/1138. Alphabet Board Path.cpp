// https://zxi.mytechroad.com/blog/geometry/leetcode-1138-alphabet-board-path/
class Solution {
public:
  string alphabetBoardPath(string target) {    
    vector<vector<string>> paths(26, vector<string>(26));
    for (int s = 0; s < 26; ++s)
      for (int t = 0; t < 26; ++t) {
        int dx = t % 5 - s % 5;
        int dy = t / 5 - s / 5; 
        string path;
        while (dx < 0) { path.push_back('L'); dx++; }
        while (dy < 0) { path.push_back('U'); dy++; }
        while (dx > 0) { path.push_back('R'); dx--; }
        while (dy > 0) { path.push_back('D'); dy--; }
        paths[s][t] = path;
      }
    
    char l = 'a';
    string ans;
    for (char c : target) {
      ans += paths[l - 'a'][c - 'a'] + "!";
      l = c;
    }
    return ans;
  }
};
