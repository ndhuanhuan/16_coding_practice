//http://bangbingsyb.blogspot.com/2014/11/leetcode-multiply-strings.html
//http://www.cnblogs.com/grandyang/p/4395356.html
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ret(num1.size()+num2.size(),'0');
        
        for(int j=0; j<num2.size(); j++) {
            int carry = 0;
            int val = num2[j] - '0';
            for(int i=0; i<num1.size(); i++) {
                carry += ((num1[i]-'0')*val + (ret[i+j]-'0'));
                ret[i+j] = carry%10 + '0';
                carry /= 10;
            }
            if(carry!=0) ret[num1.size()+j] = carry + '0';
        }
        reverse(ret.begin(),ret.end());
        
        int count = 0;
        while(count<ret.size()-1 && ret[count]=='0') count++;
        ret.erase(0,count);
        return ret;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 2, carry = 0;
        vector<int> v(n1 + n2, 0);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < n1 + n2; ++i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        int i = n1 + n2 - 1;
        while (v[i] == 0) --i;
        if (i < 0) return "0";
        while (i >= 0) res.push_back(v[i--] + '0');
        return res;
    }
};
