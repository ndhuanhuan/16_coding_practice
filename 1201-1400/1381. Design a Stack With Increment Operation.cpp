// https://zxi.mytechroad.com/blog/stack/leetcode-1381-design-a-stack-with-increment-operation/
class CustomStack {
public:
    CustomStack(int maxSize): max_size_(maxSize) {}
    
    void push(int x) {
        if(data_.size() == max_size_) return;
        data_.push_back(x);
    }
    
    int pop() {
        if(data_.size() == 0) return -1;
        int val = data_.back();
        data_.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for(int i=0; i < min(static_cast<size_t>(k), data_.size()); ++i) {
            data_[i] += val;
        }
    }
private:
  int max_size_;
  vector<int> data_;
};
