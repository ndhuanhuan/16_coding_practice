// https://zxi.mytechroad.com/blog/hashtable/leetcode-981-time-based-key-value-store/
class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}
 
  void set(string key, string value, int timestamp) {
    s_[key].emplace(timestamp, std::move(value));
  }
 
  string get(string key, int timestamp) {
    auto m = s_.find(key);
    if (m == s_.end()) return "";    
    auto it = m->second.upper_bound(timestamp);
    if (it == begin(m->second)) return "";
    return prev(it)->second;
  }
private:
  unordered_map<string, map<int, string>> s_; 
};
