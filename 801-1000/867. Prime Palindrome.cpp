// https://zxi.mytechroad.com/blog/math/leetcode-867-prime-palindrome/
class Solution {
public:
  int primePalindrome(int N) {
    if (N <= 2) return 2;
    if (N % 2 == 0) ++N;
    while (true) {      
      if (reverse(N) == N && isPrime(N)) 
        return N;
      N += 2;
      if (N > 11 & (int)log10(N) % 2 == 1)
        // 13 -> 101
        // 1001 -> 10001                
        N = pow(10, (int)log10(N) + 1) + 1;
    }
    return -1;
  }
private:
  int reverse(int n) {
    int r = 0;
    while (n) {
      r = 10 * r + n % 10;
      n /= 10;
    }
    return r;
  }
  
  bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i)
      if (n % i == 0) return false;
    return true;
  }
};
