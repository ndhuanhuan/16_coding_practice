// https://zxi.mytechroad.com/blog/bit/leetcode-1529-bulb-switcher-iv/
class Solution {
public:
  int minFlips(string target) {
    int ans = 0; 
    int cur = 0;
    for(char c: target) {
        if(c - '0' != cur) {
            cur ^= 1;
            ans += 1;
        }
    }
      
      return ans;
  }
};
