// https://zxi.mytechroad.com/blog/simulation/leetcode-1410-html-entity-parser/
class Solution {
public:
  string entityParser(string text) {    
    map<string, string> m{
      {"&quot;", "\""}, {"&apos;", "'"}, {"&amp;", "&"}, 
      {"&gt;", ">"}, {"&lt;", "<"}, {"&frasl;", "/"}};
    string ans;
    string buf;
    for (char c : text) {
      buf += c;
      if (buf.back() != ';') continue;
      const int l = buf.size();
      for (const auto& [k, v] : m) {
        const int kl = k.length();
        if (l >= kl && buf.substr(l - kl) == k) {
          ans += buf.substr(0, l - kl) + v;
          buf.clear();
          break;
        }            
      }      
    }    
    return ans + buf;
  }
};
