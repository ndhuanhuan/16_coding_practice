//http://www.cnblogs.com/grandyang/p/4782695.html
//https://www.hrwhisper.me/leetcode-h-index-h-index-ii/

//ascending order!!!!
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), left = 0, right = len;
        while (left < right) {
            int mid = 0.5 * (left + right);
            if (citations[mid] >= len - mid) right = mid;
            else left = mid + 1;
        }
        return len - left;
    }
};
