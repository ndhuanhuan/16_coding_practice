//  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1491-average-salary-excluding-the-minimum-and-maximum-salary/
class Solution {
public:
  double average(vector<int>& salary) {
    auto [lit, hit] = minmax_element(begin(salary), end(salary));
    int sum = accumulate(begin(salary), end(salary), 0);
    return (sum - *lit - *hit) * 1.0 / (salary.size() - 2);
  }
};
