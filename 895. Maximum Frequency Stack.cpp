// https://zxi.mytechroad.com/blog/desgin/leetcode-895-maximum-frequency-stack/
class FreqStack {
public:
  FreqStack() {}
 
  void push(int x) {
    auto it = freq_.find(x);
    if (it == freq_.end())
      it = freq_.emplace(x, 0).first;    
    int freq = ++it->second;    
    if (stacks_.size() < freq) stacks_.push_back({});
    stacks_[freq - 1].push(x);
  }
 
  int pop() {    
    int x = stacks_.back().top();    
    stacks_.back().pop();
    if (stacks_.back().empty())
      stacks_.pop_back();
    auto it = freq_.find(x);
    if (!(--it->second))
      freq_.erase(it);
    return x;
  }
private:  
  vector<stack<int>> stacks_;
  unordered_map<int, int> freq_;
};
