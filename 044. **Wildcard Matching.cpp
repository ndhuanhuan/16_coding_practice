//http://www.cnblogs.com/grandyang/p/4401196.html
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];   //tricky initialization
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];  //s[i-1], p[j-1] are current characters, not previous
                }
            }
        }
        return dp[m][n];
    }
};




//https://leetcode.com/problems/wildcard-matching/discuss/17810/Linear-runtime-and-constant-space-solution
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
     bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterick = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;  
                asterick = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (asterick >= 0) {
                i = ++match;
                j = asterick + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};
