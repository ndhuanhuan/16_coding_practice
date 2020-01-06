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

// https://leetcode.com/problems/jump-game-iii/discuss/469318/C%2B%2B-Recursion-using-DFS-O(n)
class Solution {
public:
    set<int> se;   
    bool canReach(vector<int>& arr, int st) {
        if (st >= 0 && st < arr.size() && se.find(st) == se.end()) {
            se.insert(st);
            return arr[st] == 0 || canReach(arr, st + arr[st]) || canReach(arr, st - arr[st]);
        }
        return false;       
    }
};
