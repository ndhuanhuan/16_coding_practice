//http://bangbingsyb.blogspot.com/2014/11/leetcode-text-justification.html
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int start = 0, end = -1, totLen = 0;
        bool isLast = false;
        vector<string> ret;
        int i=0;
        while(i<words.size()) {
            if(words[i].size()>L) return ret;
            int newLen = totLen + (end-start+1) + words[i].size();
            if(newLen<=L) { // words[i] can be in current line
                end  = i;
                totLen += words[i].size();
                i++;
            }
            else {  // word[i-1] is the end of a line
                string line = createLine(words, L, start, end, totLen, false);
                ret.push_back(line);
                start = i;
                end = i-1;
                totLen = 0;
            }
        }
        
        string lastLine = createLine(words, L, start, end, totLen, true);
        ret.push_back(lastLine);
        return ret;
    }
    
    
    string createLine(vector<string> &words, int L, int start, int end, int totLen, bool isLast) {
        string ret;
        if(start<0 || end>=words.size() || start>end) return ret;
        ret.append(words[start]);
        int n = end-start+1;
        
        // special case: one word or last line - left justified
        if(n==1 || isLast) {
            for(int i=start+1; i<=end; i++) 
                ret.append(" " + words[i]);
            int j = L-totLen-(n-1);
            ret.append(j, ' ');
            return ret;
        }
        
        // normal case: fully justified
        int k = (L-totLen)/(n-1), m = (L-totLen)%(n-1);
        for(int i=start+1; i<=end; i++) {
            int nspace = i-start<=m ? k+1 : k;
            ret.append(nspace,' ');
            ret.append(words[i]);
        }
        return ret;
    }
};
