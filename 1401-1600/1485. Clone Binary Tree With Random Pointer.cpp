// https://www.acwing.com/file_system/file/content/whole/index/content/592764/
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */
class Solution {
    unordered_map<Node *, NodeCopy *> um;
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (!root) return NULL;

        if (um.find(root) == um.end()) {
            um[root] = new NodeCopy(root -> val);
            um[root] -> left = copyRandomBinaryTree(root -> left);
            um[root] -> right = copyRandomBinaryTree(root -> right);
            um[root] -> random = copyRandomBinaryTree(root -> random);
        }
        return um[root];
    }
};
