// https://zxi.mytechroad.com/blog/string/leetcode-1433-check-if-a-string-can-break-another-string/
class Solution {
public:
  bool checkIfCanBreak(string s1, string s2) {
    vector<int> c1(26);
    vector<int> c2(26);
    for (int i = 0; i < s1.length(); ++i) {
      ++c1[s1[i] - 'a'];
      ++c2[s2[i] - 'a'];
    }
    
    int t1 = 0;
    int t2 = 0;
    int f1 = 1;
    int f2 = 1;
    for (int i = 0; i < 26; ++i) {
      t1 += c1[i];
      t2 += c2[i];
      f1 &= t1 <= t2;
      f2 &= t2 <= t1;
    }
    
    return f1 || f2;
  }
};
