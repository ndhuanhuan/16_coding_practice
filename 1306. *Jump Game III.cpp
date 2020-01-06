// https://leetcode.com/problems/jump-game-iii/discuss/464083/C%2B%2BJava-Recursion
class Solution {
public:
    unordered_set<int> vis;
    bool canReach(vector<int>& arr, int st) {
        if (st >= 0 && st < arr.size() && vis.insert(st).second) { // a bool value indicating whether the element was successfully inserted or not
            return arr[st] == 0 ||
                canReach(arr, st + arr[st]) || canReach(arr, st - arr[st]);
        }
        return false;
    }
};
