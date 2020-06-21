// https://www.acwing.com/solution/LeetCode/content/12442/
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();
        return isValid(root, 0, n - 1, arr);
    }

    bool isValid(TreeNode *root, int start, int end, vector<int> & arr)
    {
        if (start == end && root && !root -> left && !root -> right)
            return root -> val == arr[start];
        if ((!root && start <= end) || (root && start > end)) return false;
        if (root -> val != arr[start]) return false;

        bool left = start < end ? isValid(root -> left, start + 1, end, arr) : false;
        bool right = start < end ? isValid(root -> right, start + 1, end, arr) : false;
        return left || right;
    }
};
