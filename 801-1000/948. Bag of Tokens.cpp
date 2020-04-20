//https://zxi.mytechroad.com/blog/greedy/leetcode-948-bag-of-tokens/
class Solution {
public:
  int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(begin(tokens), end(tokens));
    int points = 0;
    int ans = 0;
    int i = 0;
    int j = tokens.size() - 1;
    
    while (i <= j)
      if (P >= tokens[i]) {
        P -= tokens[i++];
        ans = max(ans, ++points);        
      } else if (points > 0) {
        P += tokens[j--];
        --points;
      } else {
        break;
      }
    return ans;
  }
};
