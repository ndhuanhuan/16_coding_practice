//http://bangbingsyb.blogspot.com/2014/11/leetcode-substring-with-concatenation.html
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> allPos;
        if(L.empty()) return allPos;
        int totalWords = L.size();
        int wordSize = L[0].size();
        int totalLen = wordSize * totalWords;
        if(S.size()<totalLen) return allPos;
        
        unordered_map<string,int> wordCount;
        for(int i=0; i<totalWords; i++)
            wordCount[L[i]]++;
        
        for(int i=0; i<=S.size()-totalLen; i++) {
            if(checkSubstring(S, i, wordCount, wordSize, totalWords))
                allPos.push_back(i);
        }
        return allPos;
    }
    
    bool checkSubstring(string S, int start, unordered_map<string,int> &wordCount, int wordSize, int totalWords) {
        if(S.size()-start+1 < wordSize*totalWords) return false;
        unordered_map<string,int> wordFound;
        
        for(int i=0; i<totalWords; i++) {
            string curWord = S.substr(start+i*wordSize,wordSize);
            if(!wordCount.count(curWord)) return false;
            wordFound[curWord]++;
            if(wordFound[curWord]>wordCount[curWord]) return false;
        }
        return true;
    }
};
