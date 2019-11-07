// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-496-next-greater-element-i/
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    stack<int> s;
    unordered_map<int, int> next;
    for (int num : nums) {
      while (!s.empty() && num > s.top()) {
        next[s.top()] = num;
        s.pop();
      }
      s.push(num);
    }
      
    vector<int> ans;
    for (int num : findNums)
      ans.push_back(next.count(num) ? next[num] : -1);
    return ans;
  }
};
