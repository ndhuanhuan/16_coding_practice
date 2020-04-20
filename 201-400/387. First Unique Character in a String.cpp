class Solution{
public:
    int firstUniqChar(string s){
        vector<int> cntChar(26,0);
        for(int i=0;i<s.size();i++){
            cntChar[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(cntChar[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
