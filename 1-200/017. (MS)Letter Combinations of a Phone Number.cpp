class Solution {
public:
const vector<string> keyboard{ " ", "", "abc", "def", // '0','1','2',...
		"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		
    vector<string> letterCombinations(string digits) {
       vector<string> result;
       if(digits.empty()) return result;
       dfs(digits,0,"",result);
       return result;
    }
    
    void dfs(const string &digits, size_t cur, string path, vector<string> &result)
    {
        if(cur==digits.length())
        {
            result.push_back(path);
            return;
        }
        for(auto c:keyboard[digits[cur] - '0'])
        {
            dfs(digits,cur+1,path+c,result);
        }
    }
};
