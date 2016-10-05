//http://bangbingsyb.blogspot.com/2014/11/leetcode-best-time-to-buy-and-sell.html
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for(int i=1; i<prices.size(); i++) {
            ret += prices[i]>prices[i-1] ? prices[i]-prices[i-1] : 0;
        }
        return ret;
    }
};
