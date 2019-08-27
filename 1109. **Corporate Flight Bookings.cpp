// https://leetcode.com/problems/corporate-flight-bookings/discuss/328871/C%2B%2BJava-with-picture-O(n)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      vector<int> res(n);
      for (auto &v : bookings) {
        res[v[0] - 1] += v[2];
        if (v[1] < n) res[v[1]] -= v[2];
      }
      for (auto i = 1; i < n; ++i) res[i] += res[i - 1]; // Tricky: it add previous value, which is dynamically changing(increase or decrease)
      return res;
    }
};
