// https://zxi.mytechroad.com/blog/geometry/leetcode-1453-maximum-number-of-darts-inside-of-a-circular-dartboard/
template <typename T,
          typename TIter = decltype(std::begin(std::declval<T>())),
          typename = decltype(std::end(std::declval<T>()))>
constexpr auto enumerate(T && iterable) {
  struct iterator {
    size_t i;
    TIter iter;
    bool operator != (const iterator & other) const { return iter != other.iter; }
    void operator ++ () { ++i; ++iter; }
    auto operator * () const { return std::tie(i, *iter); }
  };
  struct iterable_wrapper {
    T iterable;
    auto begin() { return iterator{ 0, std::begin(iterable) }; }
    auto end() { return iterator{ 0, std::end(iterable) }; }
  };
  return iterable_wrapper{ std::forward<T>(iterable) };
}
 
class Solution {
public:
  int numPoints(vector<vector<int>>& points, int r) {
    const int n = points.size();
    vector<vector<double>> d(n, vector<double>(n));
    
    for (const auto& [i, pi] : enumerate(points))  
      for (const auto& [j, pj] : enumerate(points))
        d[i][j] = d[j][i] = sqrt((pi[0] - pj[0]) * (pi[0] - pj[0]) 
                               + (pi[1] - pj[1]) * (pi[1] - pj[1]));
        
    int ans = 1;
    for (const auto& [i, pi] : enumerate(points)) {    
      vector<pair<double, int>> angles; // {angle, event_type}
      for (const auto& [j, pj] : enumerate(points)) {
        if (i != j && d[i][j] <= 2 * r) {
          const double a = atan2(pj[1] - pi[1], pj[0] - pi[0]);
          const double b = acos(d[i][j] / (2 * r));
          angles.emplace_back(a - b, -1); // entering
          angles.emplace_back(a + b, 1); // exiting
        }
      }
      // If angles are the same, entering points go first.
      sort(begin(angles), end(angles));
      int pts = 1;
      for (const auto& [_, event] : angles)
        ans = max(ans, pts -= event);
    }
    return ans;
  }
};
