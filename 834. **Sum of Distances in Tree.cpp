// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C%2B%2BJavaPython-Pre-order-and-Post-order-DFS-O(N)
// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130567/Two-traversals-O(N)-python-solution-with-Explanation
// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/132133/Intuition-of-O(n)-solution-based-on-%22undirected%22-tree
class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;

    }
    
    // use post order to calculate count of each tree, also sum distance of each tree
    void dfs(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];  // Tricky! total distance: repeatly count previous node
        }
    }

    void dfs2(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
};
