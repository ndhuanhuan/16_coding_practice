//http://www.cnblogs.com/grandyang/p/4030114.html
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else if ((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else {
                ++left; --right;
            }
        }
        return true;
    }
};





class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isAlphaNum(s[left])) ++left;
            else if (!isAlphaNum(s[right])) --right;
            else if ((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else {
                ++left; --right;
            }
        }
        return true;
    }
    bool isAlphaNum(char &ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
};
