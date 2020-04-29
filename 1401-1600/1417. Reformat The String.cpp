class Solution {
public:
    string reformat(string s) {
        if(s.size() ==0) return "";
        const int n = s.size();
        vector<char> charV, digitsV;
        for(auto c: s) {
            if(c >= '0' && c <= '9') {
                digitsV.push_back(c);
            } else {
                charV.push_back(c);
            }
        }
        
        int diff = digitsV.size() - charV.size();
        
        if(abs(diff) > 1) {
          return "";
        }
        
        string res;
        
        if(abs(diff) == 0) {
            for(int i = 0; i < n ; ++i) {
                if(i%2 == 0) {
                   res += digitsV[i/2];
                } else {
                   res += charV[i/2];
                }
            }
        } else {
            for(int i = 0; i < n - 1; ++i) {
                if(i%2 == 0) {
                   res += digitsV[i/2];
                } else {
                   res += charV[i/2];
                }
            }
            
            if(digitsV.size() > charV.size()) {
                res += digitsV[digitsV.size() - 1];
            } else {
                res = charV[charV.size() - 1] + res;
            }
        }    
        
        return res;
        
    }
};
