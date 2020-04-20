// https://zxi.mytechroad.com/blog/simulation/leetcode-405-convert-a-number-to-hexadecimal/
constexpr char kHex[] = "0123456789abcdef";
 
class Solution {
public:
  string toHex(int num) {
    if (num == 0) return "0";
    long t = num < 0 ? (1LL << 32) + num : num;
    string ans;    
    while (t) {
      ans = kHex[t % 16] + ans;
      t /= 16;
    }
    return ans;
  }
};
