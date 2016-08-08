http://www.cnblogs.com/grandyang/p/4843654.html
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            int cnt=0;
            for(auto a:nums)
            {
                if(a<=mid) cnt++;
            }
            if(cnt<=mid) low = mid+1;
            else high = mid;
        }
        return low;
    }
};
