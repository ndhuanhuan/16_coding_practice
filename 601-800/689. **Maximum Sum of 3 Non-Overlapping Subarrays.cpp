// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108231/C%2B%2BJava-DP-with-explanation-O(n)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // sum[i] means nums[0] + nums[1] + ... + nums[i-1]
        vector<int> sum = {0};
        for (int& num:nums) {
            sum.push_back(sum.back() + num);
        }
        
        // posLeft[i] means if the middle interval start index is i, what's the index for left interval 
        // such that left interval has the maximum sum.
        // initial value is 0 because if middle interval start index is k, then left interval start index is 0.
        vector<int> posLeft(n, 0); 
        int leftMaxSum = sum[k] - sum[0]; // if left interval start index is 0, what's the sum of the left interval
        int leftMaxSumIndex = 0;
        // middle interval start index can only be k, k + 1, ... , n - 2*k and we start from k + 1 
        // since i = k is our initial value.
        for (int i = k + 1; i <= n - 2*k; i++) {
            if (sum[i]-sum[i-k] > leftMaxSum) {
                posLeft[i] = i-k;
                leftMaxSum = sum[i]-sum[i-k];
                leftMaxSumIndex = i-k; // if left interval start index is i - k, the sum of the left interval is bigger.
            } else {
                posLeft[i] = leftMaxSumIndex;
            } 
        }
        
        
        // posRight[i] means if the middle interval start index is i, what's the index for right interval 
        // such that right interval has the maximum sum.
        // initial value is n-k because if middle interval start index is n - 2*k, then right interval start index is n-k.
        vector<int> posRight(n,n-k);
        int rightMaxSum = sum[n] - sum[n-k];
        int rightMaxSumIndex = n-k;
        // caution: the condition is ">= tot" for right interval, and "> tot" for left interval
        // middle interval start index can only be n - 2*k, n - 2*k - 1, ... , k and we start from n - 2*k - 1
        // since i = n - 2*k is our initial value
        for (int i = n - 2*k - 1; i >= k; i--) {
            if (sum[i+2*k]-sum[i+k] >= rightMaxSum) {
                posRight[i] = i + k;
                rightMaxSum = sum[i+2*k]-sum[i+k];
                rightMaxSumIndex = i + k;
            } else {
                posRight[i] = rightMaxSumIndex;
            }
        }
        int maxSum = 0;
        vector<int> ans(3,0);
        // test all possible middle interval
        for (int i = k; i <= n-2*k; i++) {
            int l = posLeft[i], r = posRight[i];
            int totalSum = (sum[i+k]-sum[i]) + (sum[l+k]-sum[l]) + (sum[r+k]-sum[r]);
            if (totalSum > maxSum) {
                maxSum = totalSum;
                ans = {l, i, r};
            }
        }
        return ans;
    }
};
