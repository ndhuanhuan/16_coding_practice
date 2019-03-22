// https://zxi.mytechroad.com/blog/string/leetcode-890-find-and-replace-pattern/
class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {    
    vector<string> ans;
    for (const string& w : words)
      if (match(w, pattern)) ans.push_back(w);
    return ans;
  }
private:
  bool match(const string& w, const string& p) {
    vector<int> last_pos_w(128, INT_MIN); // last pos of x in w
    vector<int> last_pos_p(128, INT_MIN); // last pos of x in p
    for (int i = 0; i < w.size(); ++i)
      if (last_pos_w[w[i]] != last_pos_p[p[i]]) {
        return false;
      } else {
        last_pos_w[w[i]] = last_pos_p[p[i]] = i;
      }
    return true;
  }
};
