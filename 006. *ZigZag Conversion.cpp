//http://bangbingsyb.blogspot.com/2014/11/leetcode-zigzag-conversion.html
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<2) return s;
        string ret;
        int inc = (nRows-1)*2;  // nRows>1, otherwise infinite while loop
        for(int i=0; i<nRows; i++) {
            int j = i, d1 = (nRows-i-1)*2;
            while(j<s.size()) {
                ret.push_back(s[j]);
                if(d1!=0 && d1!=inc && j+d1<s.size()) 
                    ret.push_back(s[j+d1]);
                j += inc;
            }
        }
        return ret;
    }
};
