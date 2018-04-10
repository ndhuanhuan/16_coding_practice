
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems?page=2




class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};


//http://www.cnblogs.com/grandyang/p/4340948.html
class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        unordered_map<char, int> m;
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }
        for (int right = 0; right < S.size(); ++right) {
            if (m.find(S[right]) != m.end()) {
                --m[S[right]];
                if (m[S[right]] >= 0) ++count;
                while (count == T.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (m.find(S[left]) != m.end()) {
                        ++m[S[left]];
                        if (m[S[left]] > 0) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};
