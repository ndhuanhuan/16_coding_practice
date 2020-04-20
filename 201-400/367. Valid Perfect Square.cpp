https://www.hrwhisper.me/leetcode-valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int r=num/2+1;
        if(num==0||num==1) return true;
        while(l<=r)
        {
            long long m = l+(r-l)/2;
            long long temp = m*m;
            if(temp==num)
            {
                return true;
            }
            else if(temp>num)
            {
                r=m-1;                
            }
            else
            {
                l=m+1;
            }
        }
        return false;
    }
};
