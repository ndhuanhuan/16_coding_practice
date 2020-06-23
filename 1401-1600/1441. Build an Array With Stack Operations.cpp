// https://zxi.mytechroad.com/blog/simulation/leetcode-1441-build-an-array-with-stack-operations/
class Solution {
public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int i = 1;
    for (int num : target) {      
      while (i != num) {
        ans.push_back("Push");     
        ans.push_back("Pop");
        ++i;
      }
      ans.push_back("Push");
      ++i;
    }
    return ans;
  }
};
