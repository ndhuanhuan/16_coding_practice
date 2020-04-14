// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/discuss/564287/C%2B%2BJava-O(n)
class Solution {
public:
  int numSteps(string s) {
    int ans = 0;
    int carry = 0;
    // The highest bit must be 1, 
    // process to the 2nd highest bit
    for (int i = s.length() - 1; i > 0; --i) {
      if (s[i] - '0' + carry == 1) {
        ans += 2; // odd: +1, even: / 2
        carry = 1; // always has a carry
      } else {
        ans += 1; // even: / 2
        // carry remains same e.g. 1 + 1(carry) = 10, or 0 + 0(carry) = 00
      }
    }
    // If there is a carry, then it's even, one more step.
    return ans + carry;
  }
};
