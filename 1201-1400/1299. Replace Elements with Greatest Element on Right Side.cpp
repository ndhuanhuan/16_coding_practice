class Solution {
public:
  vector<int> replaceElements(vector<int>& arr) {
    int g = -1;
    for (int i = arr.size() - 1; i >= 0; --i)      
      g = max(g, exchange(arr[i], g));    
    return arr;
  }
};
