//http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-639-decode-ways-ii/

4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
// Author: Huahua
// Runtime: 58 ms
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;        
        //           dp[-1]  dp[0]
        long dp[2] = {1, ways(s[0])};
        for (int i = 1; i < s.length(); ++i) {
            long dp_i = ways(s[i]) * dp[1] + ways(s[i - 1], s[i]) * dp[0];
            dp_i %= kMod;
            dp[0] = dp[1];
            dp[1] = dp_i;
        }
        return dp[1];
    }
private:
    static constexpr int kMod = 1000000007;    
    
    int ways(char c) {
        if (c == '0') return 0;
        if (c == '*') return 9;
        return 1;
    }
    
    int ways(char c1, char c2) {
        if (c1 == '*' && c2 == '*') 
            return 15;
        if (c1 == '*') {
          return (c2 >= '0' && c2 <= '6') ? 2 : 1;
        } else if (c2 == '*') {
            switch (c1) {
                case '1': return 9;
                case '2': return 6;
                default: return 0;
            }
        } else {
            int prefix = (c1 - '0') * 10 + (c2 - '0');
            return prefix >= 10 && prefix <= 26;
        }        
    }
};




//https://leetcode.com/problems/decode-ways-ii/discuss/105265/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), p = 1000000007;
        // f2 is the answer to sub string ending at position i; Initially i = 0.
        long f1 = 1, f2 = helper(s.substr(0,1));
        // DP to get f2 for sub string ending at position n-1;
        for (int i = 1; i < n; i++) {
            long f3 = (f2*helper(s.substr(i, 1)))+(f1*helper(s.substr(i-1, 2)));
            f1 = f2;
            f2 = f3%p;
        }
        return f2;
    }
private:
    int helper(string s) {
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            return s[0] == '0'? 0:1;
        }
        // 11-26, except 20 because '*' is 1-9
        if (s == "**")  
            return 15;
        else if (s[1] =='*') {
            if (s[0] =='1') return 9;
            return s[0] == '2'? 6:0;
        }
        else if (s[0] == '*') 
            return s[1] <= '6'? 2:1;
        else 
            // if two digits, it has to be in [10 26]; no leading 0
            return stoi(s) >= 10 && stoi(s) <= 26? 1:0; 
    }
};

