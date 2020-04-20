// https://leetcode.com/problems/rabbits-in-forest/discuss/114721/C%2B%2BJavaPython-Easy-and-Concise-Solution
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for (int i : answers) c[i]++;
        int res = 0;
        for (auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;
    }
};
