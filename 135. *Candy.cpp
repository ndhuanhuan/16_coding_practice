//http://www.cnblogs.com/grandyang/p/4575026.html
class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        vector<int> num(ratings.size(), 1);
        for (int i = 0; i < (int)ratings.size() - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) num[i + 1] = num[i] + 1;
        }
        for (int i = (int)ratings.size() - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) num[i - 1] = max(num[i] + 1, num[i - 1]);
        }
        for (int i = 0; i < num.size(); ++i) {
            res += num[i];
        }
        return res;
    }
};
