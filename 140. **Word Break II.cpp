//http://www.cnblogs.com/grandyang/p/4576240.html
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        string out;
        vector<bool> possible(s.size() + 1, true);
        wordBreakDFS(s, wordDict, 0, possible, out, res);
        return res;
    }
    void wordBreakDFS(string &s, unordered_set<string> &wordDict, int start, vector<bool> &possible, string &out, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(out.substr(0, out.size() - 1));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i - start + 1);
            if (wordDict.find(word) != wordDict.end() && possible[i + 1]) {
                out.append(word).append(" ");
                int oldSize = res.size();
                wordBreakDFS(s, wordDict, i + 1, possible, out, res);
                if (res.size() == oldSize) possible[i + 1] = false;
                out.resize(out.size() - word.size() - 1);
            }
        }
    }
};



class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(find(wordDict.begin(),wordDict.end(),word)!=wordDict.end()){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,wordDict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};
