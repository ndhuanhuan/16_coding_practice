// https://zxi.mytechroad.com/blog/simulation/leetcode-1342-number-of-steps-to-reduce-a-number-to-zero/
class Solution {
public:
  int numberOfSteps (int num) {
    int steps = 0;
    while (num) {
      if (num & 1)
        --num; 
      else 
        num >>= 1;
      ++steps;
    }
    return steps;
  }
};
