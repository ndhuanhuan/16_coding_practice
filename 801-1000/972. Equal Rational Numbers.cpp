//https://zxi.mytechroad.com/blog/math/leetcode-972-equal-rational-numbers/
class Solution {
public:
  bool isRationalEqual(string S, string T) {
    auto convert = [](string s) {
      // 0.1234(567)
      // 01234567890
      // i = 1, p = 6
      auto i = s.find('.');
      auto p = s.find('(');
      if (p != string::npos) {
        string r = s.substr(p + 1, s.length() - p - 2);
        s = s.substr(0, p);
        while (s.length() < 16)
          s += r;
      }
      return stod(s);
    };    
    return abs(convert(S) - convert(T)) < 1e-10;
  }
};
