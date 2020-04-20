// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-905-sort-array-by-parity/
class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> even;
    vector<int> odd;
    for (int a : A) {
      if (a % 2) odd.push_back(a);
      else even.push_back(a);
    }
    even.insert(end(even), begin(odd), end(odd));
    return even;
  }
};
