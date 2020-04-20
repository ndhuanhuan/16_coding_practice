class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		traverse(root, 0, result, true);
		return result;
	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result,
		bool left_to_right) {
		if (!root) return;
		if (level == result.size())
			result.push_back(vector<int>());
		if (left_to_right)
			result[level].push_back(root->val);
		else
			result[level].insert(result[level].begin(), root->val);
		traverse(root->left, level + 1, result, !left_to_right);
		traverse(root->right, level + 1, result, !left_to_right);
	}
};
