//https://zxi.mytechroad.com/blog/queue/leetcode-933-number-of-recent-calls/
class RecentCounter {
public:
    RecentCounter() {}
    
    int ping(int t) {
      while (!q.empty() && t - q.front() > 3000) q.pop();
      q.push(t);
      return q.size();
    }
private:
  queue<int> q;
};
