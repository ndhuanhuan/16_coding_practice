// https://leetcode.com/problems/car-fleet/discuss/139850/C%2B%2BJavaPython-Straight-Forward
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double> m;
        for (int i = 0; i < pos.size(); i++) m[-pos[i]] = (double)(target - pos[i]) / speed[i];
        int res = 0; double cur = 0;
        for (auto it : m) if (it.second > cur) cur = it.second, res++;  // it* spend longer time than previous car(position > cur it car), add a new car fleet
        return res;
    }
};
