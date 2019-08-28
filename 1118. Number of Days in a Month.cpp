
class Solution {
public:
    int numberOfDays(int Y, int M) {
        
        int d[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        return M != 2?
                        d[M-1]:
                               Y%400==0?29:Y%25==0?28:Y%4==0?29:28;
        
        
    }
};
