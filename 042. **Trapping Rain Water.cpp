//http://www.cnblogs.com/grandyang/p/4402392.html
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int res = 0, left = 0, right = n-1;
        while (left < right) {
            int mn = min(height[left], height[right]);
            if (height[left] == mn) {
                ++left;
                while (left < right && height[left] < mn) {
                    res += (mn - height[left]);
                    ++left;
                }
            } else {
                --right;
                while (left < right && height[right] < mn) {
                    res += (mn - height[right]);
                    --right;
                }
            }
        }
        return res;
    }
};
