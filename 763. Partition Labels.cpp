// https://zxi.mytechroad.com/blog/string/leetcode-763-partition-labels/
class Solution {
public:
    vector<int> partitionLabels(string S) {
      vector<int> ans;
      size_t start = 0;
      size_t end = 0;
      for (size_t i = 0; i < S.size(); ++i) {
        end = max(end, S.find_last_of(S[i]));
        if (i == end) {
          ans.push_back(end - start + 1);
          start = end + 1;
        }
      }
      return ans;
    }
};
