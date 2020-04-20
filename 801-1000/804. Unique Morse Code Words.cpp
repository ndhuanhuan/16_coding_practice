// https://zxi.mytechroad.com/blog/string/leetcode-804-unique-morse-code-words/
class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> s;
    for (const string& word : words) {
      string code;
      for (char c : word)
        code += m[c - 'a'];
      s.insert(code);
    }
    return s.size();
  }
};
