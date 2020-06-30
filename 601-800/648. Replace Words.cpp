// https://zxi.mytechroad.com/blog/string/leetcode-648-replace-words/
class TrieNode {
public:
  TrieNode(): children(26), is_word(false) {}
  ~TrieNode() {
    for (int i = 0; i < 26; ++i)
      if (children[i]) {
        delete children[i];
        children[i] = nullptr;
      }
  }
  vector<TrieNode*> children;
  bool is_word;
};
class Solution {
public:
  string replaceWords(vector<string>& dict, string sentence) {    
    TrieNode root;
    for (const string& word : dict) {
      TrieNode* cur = &root;
      for (char c : word) {        
        if (!cur->children[c - 'a']) cur->children[c - 'a'] = new TrieNode();
        cur = cur->children[c - 'a'];
      }
      cur->is_word = true;
    }
    
    string ans;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {      
      TrieNode* cur = &root;
      bool found = false;
      int len = 0;
      for (char c : word) {        
        cur = cur->children[c - 'a'];        
        if (!cur) break;
        ++len;
        if (cur->is_word) {
          found = true;
          break;
        }
      }      
      if (!ans.empty()) ans += ' ';      
      ans += found ? word.substr(0, len) : word;
    }
    return ans;
  }
};
