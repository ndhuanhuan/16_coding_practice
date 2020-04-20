class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    // xors[i + 1] = arr[0] ^ arr[1] ^ ... ^ arr[i]
    vector<int> xors(arr.size() + 1);
    for (int i = 0; i < arr.size(); ++i) {
      xors[i + 1] = xors[i] ^ arr[i];
    }
    vector<int> ans;
    for (const auto& q : queries) {
      const int l = q[0];
      const int r = q[1];
      ans.push_back(xors[r + 1] ^ xors[l]);
    }
    return ans;
  }
};
