// https://zxi.mytechroad.com/blog/tree/742-closest-leaf-in-a-binary-tree/
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        graph_.clear();
        start_ = nullptr;
        buildGraph(root, nullptr, k);
        queue<TreeNode*> q;
        q.push(start_);
        unordered_set<TreeNode*> seen;
        while (!q.empty()) {
            int size = q.size();
            while (size-->0) {
                TreeNode* curr = q.front();
                q.pop();                
                seen.insert(curr);                
                if (!curr->left && !curr->right) return curr->val;
                for (TreeNode* node : graph_[curr])
                    if (!seen.count(node)) q.push(node);
            }
        }
        return 0;
    }
private:
    void buildGraph(TreeNode* node, TreeNode* parent, int k) {
        if (!node) return;
        if (node->val == k) start_ = node;
        if (parent) {
            graph_[node].push_back(parent);
            graph_[parent].push_back(node);
        }
        buildGraph(node->left, node, k);
        buildGraph(node->right, node, k);
    }
    
    unordered_map<TreeNode*, vector<TreeNode*>> graph_;
    TreeNode* start_;
};
