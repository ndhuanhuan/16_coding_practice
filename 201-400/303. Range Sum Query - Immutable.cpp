class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for(const auto& num:nums)
        {
            accu.push_back(accu.back()+num);
        }
    }

    int sumRange(int i, int j) {
        return accu[j+1]-accu[i];
    }
    
    vector<int> accu;
};
