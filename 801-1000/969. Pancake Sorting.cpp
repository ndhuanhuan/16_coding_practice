//https://zxi.mytechroad.com/blog/simulation/leetcode-969-pancake-sorting/
class Solution {
public:
  vector<int> pancakeSort(vector<int>& A) {
    const int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n - 1; ++i) {
      int p = max_element(begin(A), end(A) - i) - begin(A);
      ans.push_back(p + 1);
      std::reverse(begin(A), begin(A) + p + 1);
      ans.push_back(n - i);
      std::reverse(begin(A), begin(A) + n - i);
    }    
    return ans;
  }
};
