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




//https://leetcode.com/problems/text-justification/discuss/24873/Share-my-concise-c++-solution-less-than-20-lines

    //   0   1  2    3
    // "This is an example..."
    //  i=0, j=3, width=8, space=(16-8)/(3-0-1)=4, extra=0
    // ------------------------------------------------------
    //   3      4   5        6
    // "example of text justification."
    //  i=3, j=6, width=13, space=(16-13)/(3-0-1)=1, extra=1
    // ------------------------------------------------------
    // "justification."
    //  i=6, j=7, space=1, extra=0
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        for (int i = 0, j; i < words.length; ) {
            int width = 0;                                  // width of words without space
            for (j = i; j < words.length && width + words[j].length() + (j - i) <= maxWidth; j++)
                width += words[j].length();                 /* j is the next word */
            
            int space = 1, extra = 0;                       // for last line, space=1
            if (j - i != 1 && j != words.length) {          // not 1 word (div-by-zero) and not last line
                space = (maxWidth - width) / (j - i - 1);   // minus 1 to exclude skip last word
                extra = (maxWidth - width) % (j - i - 1);
            }
            
            StringBuilder line = new StringBuilder(words[i]);
            for (i = i + 1; i < j; i++) {                   // move i to j finally
                for (int s = space; s > 0; s--) line.append(" ");
                if (extra-- > 0) line.append(" ");
                line.append(words[i]);
            }
            for (int s = maxWidth - line.length(); s > 0; s--) line.append(" ");
            result.add(line.toString());
        }
        return result;
    }


//rewrite in c++
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0, j; i < words.size(); ) {
            int width = 0;                                  // width of words without space
            for (j = i; j < words.size() && width + words[j].size() + (j - i) <= maxWidth; j++)
                width += words[j].size();                 /* j is the next word */
            
            int space = 1, extra = 0;                       // for last line, space=1
            if (j - i != 1 && j != words.size()) {          // not 1 word (div-by-zero) and not last line
                space = (maxWidth - width) / (j - i - 1);   // minus 1 to exclude skip last word
                extra = (maxWidth - width) % (j - i - 1);
            }
            
            string line;
            line += words[i];
            for (i = i + 1; i < j; i++) {                   // move i to j finally
                for (int s = space; s > 0; s--) line += " ";
                if (extra-- > 0) line += " ";
                line += words[i];
            }
            for (int s = maxWidth - line.size(); s > 0; s--) line += " ";
            res.push_back(line);
        }
        return res;
    }
};
