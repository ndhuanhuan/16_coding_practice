// https://zxi.mytechroad.com/blog/hashtable/leetcode-904-fruit-into-baskets/
class Solution {
public:
  int totalFruit(vector<int>& tree) {        
    map<int, int> idx; // {fruit -> last_index}
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < tree.size(); ++i) {
      int f = tree[i];
      if (!idx.count(f)) {
        if (idx.size() == 2) {
          auto it1 = begin(idx);
          auto it2 = next(it1);
          if (it1->second > it2->second) swap(it1, it2);
          cur = i - it1->second - 1;          
          idx.erase(it1);          
        }       
      }      
      idx[f] = i;      
      ans = max(++cur, ans);
    }
    return ans;
  }
};
