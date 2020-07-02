// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1471-the-k-strongest-values-in-an-array/
class Solution {
public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    const int n = arr.size();
    const int i = (n - 1) / 2;
    // sort(begin(arr), end(arr));
    nth_element(begin(arr), begin(arr) + i, end(arr));
    const int m = arr[i];  
    sort(begin(arr), end(arr), [&](const int x, const int y) {      
      return abs(x - m) != abs(y - m) ? abs(x - m) > abs(y - m) : x > y;      
    });    
    return {begin(arr), begin(arr) + k};
  }
};
