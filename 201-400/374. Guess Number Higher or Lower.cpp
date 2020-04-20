// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        int left=0, right=n;
        int result,mid;
        while(result!=0)
        {   
            mid = left + (right - left) / 2;
            result = guess(mid);
            if(result==-1)
            {
                right=mid-1;
            }
            else if(result==1)
            {
               left=mid+1;
            }
        }
        return mid; 
    }
};