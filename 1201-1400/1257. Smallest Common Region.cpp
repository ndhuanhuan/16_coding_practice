// lowest common ancestor of n-ary tree
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        
        // construct the tree, record the parents
        unordered_map<string, string> tree;
        for (auto & v : regions) {
            for (int i = v.size() - 1; i > 0; --i) {
                tree[v[i]] = v[0];
            }
        }
        
		// travel up
        unordered_set<string> visited;
        while (tree.count(region1)) {
            if (region1 == region2) {
                return region1;
            }
            visited.insert(region1);
            region1 = tree[region1];
        }

        while (tree.count(region2)) {
            if (visited.count(region2)) {
                return region2;
            }
            region2 = tree[region2];
        }
        
        return region1;
    }
};
