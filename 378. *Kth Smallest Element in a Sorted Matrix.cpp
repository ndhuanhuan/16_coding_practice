class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back(); //the range of number is left-right
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;   //pickup a random number
            for (int i = 0; i < matrix.size(); ++i) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();  //find total numbers smaller than mid
            }
            if (cnt < k) left = mid + 1;  //binary search
            else right = mid;
        }
        return left;
    }
};
