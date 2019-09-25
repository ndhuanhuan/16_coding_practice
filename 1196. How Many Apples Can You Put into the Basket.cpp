// How to prove?
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        int weight = 0;
        for (int i=0; i < arr.size(); ++i)
            if (weight + arr[i] <= 5000) {
                weight += arr[i];
                ++ans;
            }
        return ans;
    }
};
