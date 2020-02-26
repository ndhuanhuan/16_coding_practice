// https://zxi.mytechroad.com/blog/simulation/eetcode-1354-construct-target-array-with-multiple-sums/
class Solution {
public:
  bool isPossible(vector<int>& target) {
    priority_queue<int> q(begin(target), end(target));
    long sum = accumulate(begin(target), end(target), 0LL);    
    while (true) {      
      int t = q.top(); q.pop();
      sum -= t;
      if (t == 1 || sum == 1) return true;      
      if (t < sum || sum == 0 || t % sum == 0) return false;
      t %= sum;
      sum += t;
      q.push(t);
    }
    return true;
  }
};
