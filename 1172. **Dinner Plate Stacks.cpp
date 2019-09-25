// https://zxi.mytechroad.com/blog/stack/leetcode-1172-dinner-plate-stacks/
class DinnerPlates {
public:
  DinnerPlates(int capacity): cap_(capacity) {}
 
  void push(int val) {  
    int index = aval_.empty() ? stacks_.size() : *begin(aval_);
    if (index == stacks_.size()) stacks_.emplace_back();
    stack<int>& s = stacks_[index];
    s.push(val);
    if (s.size() == cap_)
      aval_.erase(index);
    else if (s.size() == 1) // only insert for the first element
      aval_.insert(index);
  }
 
  int pop() { return popAtStack(stacks_.size() - 1); }
 
  int popAtStack(int index) {
    if (index < 0 || index >= stacks_.size() || stacks_[index].empty()) return -1;
    stack<int>& s = stacks_[index];
    int val = s.top(); s.pop();
    if (s.size() == cap_ - 1) aval_.insert(index);    
    
    // Amortized O(1)
    auto it = prev(end(aval_));
    while (stacks_.size() && stacks_.back().empty()) {
      stacks_.pop_back();
      aval_.erase(it--);
    }
    return val;
  }
private:
  int cap_;
  set<int> aval_;   // set used as bst
  vector<stack<int>> stacks_;
};
