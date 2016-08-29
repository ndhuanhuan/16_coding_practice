//http://www.cnblogs.com/grandyang/p/5783392.html
class Solution {
public:
    Solution(vector<int> nums) {
        v=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = v;
        for (int i = 0; i < res.size(); ++i) {
            int t = rand() % res.size();
            swap(res[i], res[t]);
        }
        return res;
    }
private:
    vector<int> v;
};
