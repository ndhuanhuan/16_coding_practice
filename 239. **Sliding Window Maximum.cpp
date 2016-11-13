//http://www.cnblogs.com/grandyang/p/4656517.html
//保存数字的下标
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();           //if index is i-k , the window is full, we should pop old element.
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back(); //make sure sequence is increasing.
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
