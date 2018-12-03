//https://zxi.mytechroad.com/blog/simulation/leetcode-946-validate-stack-sequences/
class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    auto it = begin(popped);
    for (int e : pushed) {
      s.push(e);
      while (!s.empty() && s.top() == *it) {
        s.pop();
        ++it;
      }
    }
    return it == end(popped);
  }
};
