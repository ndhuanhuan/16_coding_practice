//https://zxi.mytechroad.com/blog/string/leetcode-927-three-equal-parts/
class Solution {
public:
  vector<int> threeEqualParts(vector<int>& A) {    
    string s(begin(A), end(A));
    int ones = accumulate(begin(A), end(A), 0);
    if (ones % 3 != 0) return {-1, -1};
    if (ones == 0) return {0, A.size() - 1};
    ones /= 3;
    int right = A.size() - 1;
    while (ones) if (A[right--]) --ones;
    string suffix(begin(s) + right + 1, end(s));
    size_t l = suffix.length();
    size_t left = s.find(suffix);
    if (left == std::string::npos) return {-1, -1};
    size_t mid = s.find(suffix, left + l);
    if (mid == std::string::npos 
       || mid + 2 * l > s.length()) return {-1, -1};
    return {left + l - 1, mid + l};
  }
};
