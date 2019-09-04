
class Solution {
public:
    bool isArmstrong(int N) {
        int check = N;
        int copy = N;
        long long sum = 0;
        int numDigits = 0;
        while (check != 0) {
            check /= 10;
            numDigits++;
        }
        while (copy != 0) {
            sum += pow(copy % 10, numDigits);
            copy /= 10;
        }
        if (sum == N)
            return true;
        else
            return false;
    }
};
