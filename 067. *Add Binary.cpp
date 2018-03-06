//http://bangbingsyb.blogspot.com/2014/11/leetcode-add-binary.html
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string sum;
        int carry = 0;
        int n = max(a.size(),b.size());
        for(int i=0; i<n; i++) {
            if(i<a.size()) carry+=(a[i]-'0');
            if(i<b.size()) carry+=(b[i]-'0');
            sum.push_back(carry%2+'0');
            carry/=2; 
        }
        if(carry) sum.push_back('1');
        reverse(sum.begin(),sum.end());
        return sum;
    }
};


//http://www.cnblogs.com/grandyang/p/4084971.html
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};
