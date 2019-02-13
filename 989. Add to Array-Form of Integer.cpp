//https://zxi.mytechroad.com/blog/simulation/leetcode-989-add-to-array-form-of-integer/
class Solution {
public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> ans;
    ans.reserve(A.size() + 1);    
    for (int i = A.size() - 1; i >= 0 || K > 0; --i) {
      K += (i >= 0 ? A[i] : 0);
      ans.push_back(K % 10);
      K /= 10;
    }    
    reverse(begin(ans), end(ans));
    return ans;
  }
};
