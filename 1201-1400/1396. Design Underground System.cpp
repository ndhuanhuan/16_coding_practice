// https://zxi.mytechroad.com/blog/hashtable/leetcode-1396-design-underground-system/
class UndergroundSystem {
public:
  UndergroundSystem() {}
 
  void checkIn(int id, string stationName, int t) {
    m_[id] = {stationName, t};
  }
 
  void checkOut(int id, string stationName, int t) {
    const auto& [s0, t0] = m_[id];
    string key = s0 + "_" + stationName;
    times_[key].first += (t - t0);
    ++times_[key].second;
  }
 
  double getAverageTime(string startStation, string endStation) {
    const auto& [sum, count] = times_[startStation + "_" + endStation];
    return static_cast<double>(sum) / count;
  }
private:
  unordered_map<int, pair<string, int>> m_; // id -> {station, t}
  unordered_map<string, pair<int, int>> times_; // trip -> {sum, count}
};
