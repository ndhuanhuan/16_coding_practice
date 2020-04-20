class Solution {
public:
    bool confusingNumber(int N) {
        int tmp = N;
        unordered_map<int,int> m({ { 0, 0 }, { 1, 1 }, { 9, 6 },{ 8, 8 }, { 6, 9 } });
        int res = 0;
        while(tmp > 0) {
            int num = tmp%10;
            tmp = tmp/10;
            if (!m.count(num)) return false;
            res = res*10 + m[num];
        }
        return true && res!=N;
    }
};
