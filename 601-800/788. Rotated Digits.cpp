// https://zxi.mytechroad.com/blog/string/leetcode-788-rotated-digits/
class Solution {
public:
  int isValid(int n) {
    string s = to_string(n);
    string t(s);
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '3' || s[i] == '4' || s[i] == '7')
        return 0;
      else if (s[i] == '2') t[i] = '5';
      else if (s[i] == '5') t[i] = '2';
      else if (s[i] == '6') t[i] = '9';
      else if (s[i] == '9') t[i] = '6';
    }
      
    return t != s;
  }
  
  int rotatedDigits(int N) {
    int ans = 0;
    for (int i = 1; i <= N; ++i)
      ans += isValid(i);    
    return ans;
  }
};
