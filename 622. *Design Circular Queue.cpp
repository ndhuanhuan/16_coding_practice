// https://zxi.mytechroad.com/blog/uncategorized/leetcode-622-design-circular-queue/
class MyCircularQueue {
public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k): q_(k), k_(k), tail_(-1), size_(0) {}
 
  /** Insert an element into the circular queue. Return true if the operation is successful. */
  bool enQueue(int value) {
    if (isFull()) return false;
    ++size_;
    tail_ = (tail_ + 1) % k_;
    q_[tail_] = value;
    return true;
  }
 
  /** Delete an element from the circular queue. Return true if the operation is successful. */
  bool deQueue() {
    if (isEmpty()) return false;    
    --size_;
    return true;
  }
 
  /** Get the front item from the queue. */
  int Front() {
    if (isEmpty()) return -1;
    return q_[(tail_ + k_ - size_ + 1) % k_];
  }
 
  /** Get the last item from the queue. */
  int Rear() {
    if (isEmpty()) return -1;
    return q_[tail_];
  }
 
  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() {
    return size_ == 0;
  }
 
  /** Checks whether the circular queue is full or not. */
  bool isFull() {
    return size_ == k_;
  }
private:
  const int k_;
  int tail_;
  int size_;
  vector<int> q_;
};
