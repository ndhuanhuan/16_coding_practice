// https://blog.csdn.net/Csdn_jey/article/details/92252222
class Solution {
public:
  int confusingNumberII(int N) {
    n = N;
    ans = 0;
    search(0);
    return ans;
  }
private:
  int n, ans;
  void search(long long num) {
    if (num > n) return;
    if (num) {
      if (rotate(num) != num) ++ ans;
    }
    if (num) search(num * 10);
    search(num * 10 + 1);
    search(num * 10 + 6);
    search(num * 10 + 8);
    search(num * 10 + 9);
  }
  long long rotate(long long x) {
    long long y = 0;
    for (; x; x /= 10) {
      int k = x % 10;
      switch (k) {
        case 6: k = 9; break;
        case 9: k = 6; break;
      }
      y = y * 10 + k;
    }
    return y;
  }
};
