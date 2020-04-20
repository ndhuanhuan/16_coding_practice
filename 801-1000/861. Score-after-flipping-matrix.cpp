// https://blog.csdn.net/fuxuemingzhu/article/details/81118328
class Solution {
public:
    int matrixScore(vector<vector<int>> &A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; i++)
            if (A[i][0])
                for (int j = 0; j < N; j++)
                    A[i][j] = 1 - A[i][j];
        int res = 0;
        for (int j = 0; j < N; j++) {
            int count1 = 0;
            for (int i = 0; i < M; i++) {
                if (A[i][j]) {
                    count1++;
                }
            }
            res += (1 << (N - 1 - j)) * max(count1, M - count1);
        }
        return res;
    }
};
