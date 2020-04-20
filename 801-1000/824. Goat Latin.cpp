// https://zxi.mytechroad.com/blog/string/leetcode-824-goat-latin/
class Solution {
public:
  string toGoatLatin(string S) {    
    const string vowls = "aeiouAEIOU";
    string ans;
    string word;
    int index = 0;
    istringstream s(S);
    while (s >> word) {
      if (vowls.find(word[0]) == string::npos)          
        word = word.substr(1) + word[0];      
      ans += " " + word + "ma" + string(++index, 'a');
    }
    return ans.substr(1);
  }
};
