// https://zxi.mytechroad.com/blog/tree/leetcode-677-map-sum-pairs/
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum(): root_(new Trie()) {}
  
    void insert(string key, int val) {      
      int inc = val - vals_[key];
      Trie* p = root_.get();
      for (const char c : key) {
        if (!p->children[c])
          p->children[c] = new Trie();
        p->children[c]->sum += inc;
        p = p->children[c];
      }
      vals_[key] = val;
    }
    
    int sum(string prefix) {
      Trie* p = root_.get();
      for (const char c : prefix) {
        if (!p->children[c]) return 0;
        p = p->children[c];
      }
 
      return p->sum;        
    }
private:
    struct Trie {
        Trie():children(128, nullptr), sum(0){}
        ~Trie() {
          for (auto child : children)
            if (child) {
              delete child;
              child = nullptr;
            }
          children.clear();
        }
        vector<Trie*> children;
        int sum;        
    };
    
    std::unique_ptr<Trie> root_;
    unordered_map<string, int> vals_; // key -> val
};
