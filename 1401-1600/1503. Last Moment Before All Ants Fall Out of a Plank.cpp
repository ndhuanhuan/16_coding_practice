// https://zxi.mytechroad.com/blog/math/leetcode-1503-last-moment-before-all-ants-fall-out-of-a-plank/
class Solution {
public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    const int t1 = left.empty() ? 0 : *max_element(cbegin(left), cend(left));
    const int t2 = right.empty() ? 0 : n - *min_element(cbegin(right), cend(right));
    return max(t1, t2);
  }
};
