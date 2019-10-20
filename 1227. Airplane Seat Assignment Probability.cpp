// https://medium.com/i-math/solving-an-advanced-probability-problem-with-virtually-no-math-5750707885f1
class Solution 
{
    public:
    double nthPersonGetsNthSeat(int n) 
    {
        return n==1?1:0.5;
    }
};
