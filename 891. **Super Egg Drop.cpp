// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-891-super-egg-drop/
class Solution {
public:
  int superEggDrop(int K, int N) {    
    m_ = vector<vector<int>>(K + 1, vector<int>(N + 1, INT_MIN));
    return dp(K, N);
  }
private:
  // m[i][j] := min moves of i eggs and j floors
  vector<vector<int>> m_;
  
  int dp(int k, int n) {
    if (k <= 0) return 0;
    if (k == 1) return n;
    if (n <= 1) return n;
    if (m_[k][n] != INT_MIN) return m_[k][n];
        
    // broken[i]   = dp(k - 1, i - 1) is incresing with i.
    // unbroken[i] = dp(k,     n - i) is decresing with i.
    // dp[k][n] = 1 + min(max(broken[i], unbroken[i])), 1 <= i <= n
    // find the smallest i such that broken[i] >= unbroken[i],
    // which minimizes max(broken[i], unbroken[i]).
    int l = 1;
    int r = n + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      int broken = dp(k - 1, m - 1);
      int unbroken = dp(k, n - m);
      if (broken >= unbroken)
        r = m;
      else
        l = m + 1;
    }
    
    return m_[k][n] = 1 + dp(k - 1, l - 1);
  }
};




// https://leetcode.com/problems/super-egg-drop/discuss/158974/C%2B%2BJavaPython-2D-and-1D-DP-O(KlogN)
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
};


// https://www.cnblogs.com/Phantom01/p/9490508.html
// https://www.acwing.com/solution/leetcode/content/579/
// 因此，这次扔鸡蛋，我们最多能测出 dp[k-1][m-1] (摔碎时能确定的层数) + dp[k][m-1] (没摔碎时能确定的层数) + 1 (本层) 层的结果。
// Note: 我一直不理解为什么是加在一起， 现在明白了, 因为一共两种可能， 碎了或者不碎（必然其中之一）， 两种可能总共cover了 dp[k-1][m-1] (摔碎时能确定的层数) + dp[k][m-1] (没摔碎时能确定的层数) + 1 (本层)
