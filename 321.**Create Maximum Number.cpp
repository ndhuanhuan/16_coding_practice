//http://www.cnblogs.com/grandyang/p/5136749.html
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res;
        for(int i=max(0,k-n);i<=min(k,m);++i)
        {
            res = max(res, mergeVector(maxVector(nums1,i),maxVector(nums2,k-i)));
        }
        return res;
    }
    
    vector<int> maxVector(vector<int> nums, int k)
    {
        int drop = nums.size()-k;
        vector<int> res;
        for (int num : nums) {
            while (drop && res.size() && res.back() < num) {
                res.pop_back();
                --drop;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    
    vector<int> mergeVector(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        while (nums1.size() + nums2.size()) {
            vector<int> &tmp = nums1 > nums2 ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
    
};



// combined  huahua and above answer
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-321-create-maximum-number/
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        for (int i = max(0, k - n2); i <= min(k, n1); ++i)
            ans = max(ans, maxNumber(maxNumber(nums1, i), 
                                     maxNumber(nums2, k - i)));
        return ans;
    }
private:    
    vector<int> maxNumber(vector<int> nums, int k) {
        int drop = nums.size() - k;
        vector<int> out;
        for (int num : nums) {
            while (drop && out.size() && out.back() < num) {
                out.pop_back();
                drop--;
            }
            out.push_back(num);
        }
        out.resize(k);
        return out;
    }
    
    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ans(nums1.size() + nums2.size());
        auto s1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto s2 = nums2.cbegin();
        auto e2 = nums2.cend();        
        int index = 0;
        while (s1 != e1 || s2 != e2)
            ans[index++] = 
              lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++;
        return ans;
    }
};
