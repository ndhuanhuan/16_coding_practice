//Unfamiliar with this type of questions
//http://www.cnblogs.com/grandyang/p/5771434.html

class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        if(s.size()<=2) return NestedInteger();
        NestedInteger res;
        int start=1,cnt=0;
        for(int i=1;i<s.size();i++)
        {
            if (cnt == 0 && (s[i] == ',' || i == s.size() - 1)) {
                res.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            } else if (s[i] == '[') ++cnt;
            else if (s[i] == ']') --cnt;
        }
        return res;
    }
};
