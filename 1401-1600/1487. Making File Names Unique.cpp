// https://zxi.mytechroad.com/blog/hashtable/leetcode-1487-making-file-names-unique/
class Solution {
public:
  vector<string> getFolderNames(vector<string>& names) {
    vector<string> ans;
    unordered_map<string, int> m; // base_name -> next suffix.
    for (const string& name : names) {
      string unique_name = name;
      int j = m[name];
      if (j > 0) {
        while (m.count(unique_name = name + "(" + to_string(j++) + ")"));    
        m[name] = j;        
      }
      m[unique_name] = 1;
      ans.push_back(unique_name);
    }
    return ans;
  }
};
