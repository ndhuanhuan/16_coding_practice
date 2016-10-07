//http://bangbingsyb.blogspot.com/2014/11/leetcode-palindrome-number.html//
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int res=0, y=x;
        while(y) {
            //if(abs(res)>(INT_MAX/10)) return false;
            res = res * 10 + y % 10;
            y /= 10;
        }
        return res==x;
    }
};
