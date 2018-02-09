//http://www.cnblogs.com/grandyang/p/7098764.html
//https://discuss.leetcode.com/topic/92966/java-o-n-time-o-1-space-1-pass-no-sorting-solution-with-detailed-explanation
// mx is max, mxcnt is how many mx exist
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0, mxCnt = 0;
        vector<int> cnt(26, 0);        
        for (char task : tasks) {
            ++cnt[task - 'A'];
            if (mx == cnt[task - 'A']) {
                ++mxCnt;
            } else if (mx < cnt[task - 'A']) {
                mx = cnt[task - 'A'];
                mxCnt = 1;
            }
        }
        int partCnt = mx - 1;  //Number of parts seperate by max cnt element
        int partLen = n - (mxCnt - 1);
        int emptySlots = partCnt * partLen;
        int taskLeft = tasks.size() - mx * mxCnt;
        int idles = max(0, emptySlots - taskLeft); //most hard to understand part. If emptySlots> taskleft, which means we need to add more idles.
                                                   //Otherwise, if taskleft>=emptySlots, we don't need to add any "idles", it should be able to scheduled properly.
                                                    // it equals to tasks.size()
        return tasks.size() + idles;
    }
};
