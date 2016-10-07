//http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-common-prefix.html
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string comPrefix;
        if(strs.empty()) return comPrefix;
        for(int i=0; i<strs[0].size(); i++) {
            for(int j=1; j<strs.size(); j++) {
                if(i>=strs[j].size() || strs[j][i]!=strs[0][i])
                    return comPrefix;
            }
            comPrefix.push_back(strs[0][i]);
        }
        return comPrefix;
    }
};
