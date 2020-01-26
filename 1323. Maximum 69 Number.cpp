// https://zxi.mytechroad.com/blog/greedy/leetcode-1323-maximum-69-number/
class Solution {
public:
  int maximum69Number (int num) {
    string s = to_string(num);
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '6') {
        s[i] = '9';
        return stoi(s);
      }
    }
    return num;
  }
};
