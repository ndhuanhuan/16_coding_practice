//http://www.cnblogs.com/zichi/p/4806998.html
//http://www.cnblogs.com/grandyang/p/4985506.html
//http://blog.jobbole.com/96430/
//

class NumArray {
public:
    NumArray(vector<int> &nums) {
        num.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    void update(int i, int val) {
        int diff = val - num[i + 1];
        for (int j = i + 1; j < num.size(); j += (j&-j)) {
            bit[j] += diff;
        }
        num[i + 1] = val;
    }
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }    
    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> num;
    vector<int> bit;
};
