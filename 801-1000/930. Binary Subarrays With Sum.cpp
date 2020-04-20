class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int l = 0, r = 0;
        int sum = 0;
        int cnt = 0;
        while(r < A.size())
        {
            sum += A[r];

            if(sum > S)
            {
                while(l <= r && sum > S)
                {
                    sum -= A[l];
                    l++;
                }
            }
            if(sum == S && l <= r)
            {
                cnt += 1;
                int k = l;
                while(k < r && A[k] == 0)
                    k++;
                cnt += k - l;
            }
            r++;
        }
        return cnt;
    }
};
