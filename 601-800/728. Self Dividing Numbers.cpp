// https://zxi.mytechroad.com/blog/math/leetcode-728-self-dividing-numbers/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int n = left; n <= right; ++n) {
            int t = n;
            bool valid = true;
            while (t && valid) {
                const int r = t % 10;
                if (r == 0 || n % r)
                    valid = false;
                t /= 10;
            }
            if (valid) ans.push_back(n);
        }
        return ans;
    }
};
