//To those who don’t understand why it works. Consider the example in the OJ
{1,2,3,3,3} with target 3, you want to select 2,3,4 with a probability of 1/3 each.

2 : It’s probability of selection is 1 * (1/2) * (2/3) = 1/3
3 : It’s probability of selection is (1/2) * (2/3) = 1/3
4 : It’s probability of selection is just 1/3

So they are each randomly selected.
//https://leetcode.com/problems/random-pick-index/discuss/88072/Simple-Reservoir-Sampling-solution
//http://www.cnblogs.com/grandyang/p/5875509.html
class Solution {
public:
    Solution(vector<int> nums) : v(nums){
        
    }
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) continue;
            ++cnt;
            if (rand() % cnt == 0) res = i;
        }
        return res;
    }

private:
    vector<int> v;
    
};
