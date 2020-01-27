// https://zxi.mytechroad.com/blog/greedy/leetcode-45-jump-game-ii/
// https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
// Let's say the range of the current jump is [curBegin, curEnd], curFarthest is the farthest point that all points in [curBegin, curEnd] can reach
// current point reaches curEnd, then trigger another jump, and set the new curEnd with curFarthest
class Solution {
public:
  int jump(vector<int>& nums) {
    int steps = 0;
    int curEnd = 0;
    int curFarthest = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > curEnd) {
        ++steps;
        curEnd = curFarthest;
      }
      curFarthest = max(curFarthest, i + nums[i]);      
    }
    return steps;
  }
};
