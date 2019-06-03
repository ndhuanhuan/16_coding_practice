// https://www.cnblogs.com/grandyang/p/9272921.html
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> change(n, 0);
        for (int i = 0; i < n; ++i) change[(i - A[i] + 1 + n) % n] -= 1; //change[k] 表示刚好在k时候失分的数字的"个数（count）"
        for (int i = 1; i < n; ++i) {
            change[i] += change[i - 1] + 1;  // +1 因为有一个数在左移过程中变成了最右边的数， 它一定是能得分的
            res = (change[i] > change[res]) ? i : res;
        }
        return res;
    }
};
