// https://www.cnblogs.com/grandyang/p/8850299.html
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long res = 0, sum1 = 0, sum2 = 0;
        vector<int> expect = arr;
        sort(expect.begin(), expect.end());
        for (int i = 0; i < arr.size(); ++i) {
            sum1 += arr[i];
            sum2 += expect[i];
            if (sum1 == sum2) ++res;
        }
        return res;
    }
};
