// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/discuss/327970/C%2B%2B-Sort-and-Union-Find

// tricky: I am using a negative value to indicate the root and the number of joint elements.
// so only root contains a negative number, ex: -12, others are positive numbers, postive number indicate its parent
class Solution {
public:
    int ds_find(vector<int>& ds, int i) {
      return ds[i] < 0 ? i : ds[i] = ds_find(ds, ds[i]);
    }
    int ds_union(vector<int>& ds, int i, int j) {
      i = ds_find(ds, i), j = ds_find(ds, j);
      if (i != j) {
        ds[i] += ds[j];
        ds[j] = i;
      }
      return -ds[i];
    }
    int earliestAcq(vector<vector<int>>& logs, int N) {
      vector<int> ds(N, -1);
      sort(begin(logs), end(logs));
      for (auto &l : logs)
        if (ds_union(ds, l[1], l[2]) == N) return l[0];
      return -1;
    }
};
