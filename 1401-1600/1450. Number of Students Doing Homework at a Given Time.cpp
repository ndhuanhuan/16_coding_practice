// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1450-number-of-students-doing-homework-at-a-given-time/
class Solution {
public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int ans = 0;
    for (int i = 0; i < startTime.size(); ++i)
      if (startTime[i] <= queryTime && queryTime <= endTime[i]) ++ans;
    return ans;
  }
};
