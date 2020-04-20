class Solution {
public:
    using VI = vector<int>;
    VI transformArray(VI& A, bool change=false) {
        int N = A.size();
        do {
            change = false;
            VI B(N, 0);
            for (auto i=1; i + 1 < N; ++i)
                if (A[i-1] < A[i] && A[i] > A[i+1])
                    --B[i], change = true;
                else if (A[i-1] > A[i] && A[i] < A[i+1])
                    ++B[i], change = true;
            for (auto i=1; i + 1 < N; A[i] += B[i], ++i);
        } while (change);
        return A;
    }
};
