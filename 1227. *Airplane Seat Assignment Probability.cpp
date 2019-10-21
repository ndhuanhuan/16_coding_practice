// https://medium.com/i-math/solving-an-advanced-probability-problem-with-virtually-no-math-5750707885f1
// https://leetcode.com/problems/airplane-seat-assignment-probability/discuss/407533/Python-from-O(n)-to-O(1)-with-detailed-explanation
class Solution 
{
    public:
    double nthPersonGetsNthSeat(int n) 
    {
        return n==1?1:0.5;
    }
};
