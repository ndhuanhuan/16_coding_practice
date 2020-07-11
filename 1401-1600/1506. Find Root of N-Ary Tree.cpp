// https://leetcode.com/problems/find-root-of-n-ary-tree/discuss/729168/Javascript-and-C%2B%2B-solutions
class Solution {
public:
    using Nodes = vector<Node*>;
    using Set = unordered_set<Node*>;
    Node* findRoot(Nodes tree, Set children = {}) {
        for (auto node: tree)
            for (auto child: node->children)
                children.insert(child);
        tree.erase(remove_if(tree.begin(), tree.end(), [&](auto node) { return children.find(node) != children.end(); }), tree.end());
        return tree[0]; // 🎯 root node is the only node which is *not* a child
    }
};
