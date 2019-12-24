// https://zxi.mytechroad.com/blog/heap/leetcode-703-kth-largest-element-in-a-stream/
class KthLargest {
public:
  KthLargest(int k, vector<int> nums): k_(k) {    
    for (int num : nums)
      add(num);
  }
 
  int add(int val) {    
    s_.push(val);
    if (s_.size() > k_)
      s_.pop();
    return s_.top();
  }
private:
  const int k_;  
  priority_queue<int, vector<int>, greater<int>> s_; // min heap
};
