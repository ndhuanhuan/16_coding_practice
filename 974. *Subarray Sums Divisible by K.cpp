//https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-974-subarray-sums-divisible-by-k/
class Solution {
public:
  int subarraysDivByK(vector<int>& A, int K) {    
    vector<int> c(K);
    c[0] = 1;
    int ans = 0;
    int sum = 0;
    for (int a : A) {
      sum = (sum + a % K + K) % K;
      ans += c[sum]++;
    }
    return ans;
  }
};
