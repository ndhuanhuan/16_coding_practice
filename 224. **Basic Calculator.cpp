//https://discuss.leetcode.com/topic/15775/simple-c-in-24-ms
class Solution {
public:
    int calculate(string s) {
        // the given expression is always valid!!!
        // only + and - !!!
        // every + and - can be flipped base on it's depth in ().
        stack<int> signs;
        int sign = 1;
        int num = 0;
        int ans = 0;
        
        // always transform s into ( s )
        signs.push(1);
        
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }
        
        if (num) {
            ans = ans + signs.top() * sign * num;
        }
        
        return ans;
    }
};





//http://www.cnblogs.com/grandyang/p/4570699.html
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        vector<int> sign(2, 1);
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c >= '0') {
                int num = 0;
                while (i < s.size() && s[i] >= '0') {
                    num = 10 * num + s[i++] - '0';
                }
                res += sign.back() * num;
                sign.pop_back();
                --i;
            }
            else if (c == ')') sign.pop_back();
            else if (c != ' ') sign.push_back(sign.back() * (c == '-' ? -1 : 1));  //makes everything inside () negative or positive 
        }
        return res;
    }
};
