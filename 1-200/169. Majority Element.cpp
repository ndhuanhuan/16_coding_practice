//http://www.cnblogs.com/grandyang/p/4233501.html
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int Idx = 0, count = 1;
        for (int i = 1; i < num.size(); ++i) {
            num[Idx] == num[i] ? ++count : --count;
            if (count == 0) {
                Idx = i;
                count = 1;
            }
        }
        return num[Idx];
    }
};
