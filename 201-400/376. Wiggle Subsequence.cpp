class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 1) return n;
		int i = 1;
		vector<int> pos(n, 1);
		vector<int> neg(n, 1);
		int res =1;
		for(int i=0;i<n;i++)
		{
		    for(int j=0;j<i;j++)
		    {
		         pos[i] = max(pos[i], (neg[j] + 1) * (nums[j] > nums[i]?1:-1));
                	 neg[i] = max(neg[i], (pos[j] + 1) * (nums[j] < nums[i]?1:-1));
                	 res = max({res, pos[i], neg[i]});
		    }
		}
	    return res;
	}
};

//Greedy
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 1) return n;
		int res=1, count=1;
		int prevInc=0;
		for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1] && (prevInc == 0 || prevInc==-1)) {
                prevInc = 1;
                count++;
            } else if(nums[i] < nums[i - 1] && (prevInc == 0 || prevInc==1)) {
                prevInc = -1;
                count++;
            }
            res = max(res, count);
        }
        return res;
	}
};
