// Use this: https://www.acwing.com/solution/LeetCode/content/253/
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int s = 0;
        char *p = buf, temp[4];
        while(s < n) {
            int t = read4(temp);
            for(int i=0; i < t && s < n; ++i) {
                *p++ = temp[i];
                s++;
            }
            if(t < 4) return s;
        }
        return s;
    }
};


//http://www.cnblogs.com/grandyang/p/5174322.html
class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int cur = read4(buf + res);
            if (cur == 0) break;
            res += cur;
        }
        return min(res, n);
    }
};
