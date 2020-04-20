//https://zxi.mytechroad.com/blog/string/leetcode-929-unique-email-addresses/
class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> s;
    for (const string& email : emails) {
      string e;
      bool at = false;
      bool plus = false;
      for (char c : email) {
        if (c == '.') {
          if (!at) continue;
        } else if (c == '@') {
          at = true;          
        } else if (c == '+') {
          if (!at) {
            plus = true;
            continue;
          }
        }        
        if (!at && plus) continue;
        e += c;        
      }      
      s.insert(e);
    }
    return s.size();
  }
};
