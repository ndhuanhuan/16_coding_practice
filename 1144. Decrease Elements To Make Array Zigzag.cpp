// https://zxi.mytechroad.com/blog/greedy/1144-decrease-elements-to-make-array-zigzag/

// Author: Huahua
class Solution {
public:
  int movesToMakeZigzag(vector<int>& nums) {
    const int n = nums.size();
    vector<int> moves(2);    
    for (int i = 0; i < n; i++) {
      int l = i == 0 ? INT_MAX : nums[i - 1];
      int r = i == n - 1 ? INT_MAX : nums[i + 1];
      moves[i % 2] += max(0, nums[i] - min(l, r) + 1);
    }    
    return min(moves[0], moves[1]);
  }
};


// make local minimum

// make local minimum or make local maximum are the same thing
