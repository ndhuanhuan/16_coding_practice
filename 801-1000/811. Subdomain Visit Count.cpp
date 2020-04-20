// https://zxi.mytechroad.com/blog/string/leetcode-811-subdomain-visit-count/
class Solution {
public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> counts;
    for (const string& cpdomain : cpdomains) {
      size_t index = cpdomain.find(' ');
      int count = std::stoi(cpdomain.substr(0, index));
      string domain = cpdomain.substr(index + 1);
      while (true) {
        counts[domain] += count;
        size_t i = domain.find('.');
        if (i == string::npos) break;
        domain = domain.substr(i + 1);
      }
    }
    vector<string> ans;
    for (const auto& kv : counts)
      ans.push_back(std::to_string(kv.second) + " " + kv.first);
    return ans;
  }
};
