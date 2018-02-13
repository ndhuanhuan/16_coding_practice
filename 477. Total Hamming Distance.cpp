//http://www.cnblogs.com/grandyang/p/6208062.html
//我们仔细观察累计汉明距离和0跟1的个数，
//我们可以发现其实就是0的个数乘以1的个数，
//发现了这个重要的规律，那么整道题就迎刃而解了，只要统计出每一位的1的个数即可
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int num : nums) {
                if (num & (1 << i)) ++cnt;
            }
            res += cnt * (n - cnt);
        }
        return res;
    }
};
