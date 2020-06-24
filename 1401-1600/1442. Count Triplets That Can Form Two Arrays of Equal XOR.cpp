// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1442-count-triplets-that-can-form-two-arrays-of-equal-xor/
class Solution {
public:
  int countTriplets(vector<int>& arr) {
    const int n = arr.size();    
    int ans = 0;
    unordered_map<int, int> freq{{0, 1}};    
    unordered_map<int, int> sum;
    int X = 0;
    for (int i = 0; i < n; ++i) {
      X ^= arr[i];
      ans += freq[X] * i - sum[X];
      ++freq[X];
      sum[X] += i + 1;
    }
    return ans;
  }
};
