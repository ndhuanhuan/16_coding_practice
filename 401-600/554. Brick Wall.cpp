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

//http://www.cnblogs.com/grandyang/p/6697067.html
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int mx = 0;
        unordered_map<int, int> m;
        for (auto a : wall) {
            int sum = 0;
            for (int i = 0; i < a.size() - 1; ++i) {   //we must -1 because we should not count the right most vertical edge
                sum += a[i];
                ++m[sum];
                mx = max(mx, m[sum]);
            }
        }
        return wall.size() - mx;
    }
};
