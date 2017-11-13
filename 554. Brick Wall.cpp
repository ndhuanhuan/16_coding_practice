//https://discuss.leetcode.com/topic/85785/c-java-clean-code
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> ends;
        int maxend = 0;
        for (int i = 0; i < wall.size(); i++) {
            int sum = 0;
            for (int j = 0; j + 1 < wall[i].size(); j++) {
                ends[sum += wall[i][j]]++;
                maxend = max(maxend, ends[sum]);
            }
        }

        return wall.size() - maxend;
    }
};
