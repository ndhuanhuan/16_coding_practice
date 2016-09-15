
//http://www.cnblogs.com/grandyang/p/5310649.html
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        //find celebrity candidates.
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) res = i;
        }
        
        //Verify candidates.
        for (int i = 0; i < n; ++i) {
            if (res != i && (knows(res, i) || !knows(i, res))) return -1;
        }
        return res;
    }
};
