// https://leetcode.com/problems/before-and-after-puzzle/discuss/377944/C%2B%2B-2-hash-maps-and-set
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
      unordered_map<string, set<string>> first, last;
      set<string> res;
      for (auto p : phrases) {
        auto fp = p.find(' '), lp = p.rfind(' ');
        fp = fp == string::npos ? p.size() : fp;
        lp = lp == string::npos ? 0 : lp + 1;
        for (auto pp : first[p.substr(lp)]) { res.insert(p + pp);}
        for (auto pp : last[p.substr(0, fp)]) { res.insert(pp + p);}
        first[p.substr(0, fp)].insert(p.substr(fp));
        last[p.substr(lp)].insert(p.substr(0, lp));
      }
      return vector<string>(begin(res), end(res));
    }
};


// first => key is the first word of phrase, value is the rest of phrase
// last => key is the last word of phrase, value is rest of phrase
