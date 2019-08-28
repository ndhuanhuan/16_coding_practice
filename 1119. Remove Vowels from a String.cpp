
class Solution {
public:
    string removeVowels(string S) {
        
        int j = 0;
        
        for(int i = 0 ;i<S.length();i++)
        {
            if(S[i]=='a'
              ||S[i]=='e'
              ||S[i]=='i'
              ||S[i]=='o'
              ||S[i]=='u')
                continue;
            else
                S[j++]=S[i];
        }
        
        return S.substr(0,j);
        
        
    }
};
