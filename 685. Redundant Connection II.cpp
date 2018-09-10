//https://zxi.mytechroad.com/blog/graph/leetcode-685-redundant-connection-ii/
static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        vector<int> parents(edges.size() + 1, 0);
        vector<int> roots(edges.size() + 1, 0);       
        vector<int> sizes(edges.size() + 1, 1);
        
        vector<int> ans1;
        vector<int> ans2;
        
        //inside this for loop, it is only used for handle two nodes point to one one node. 
        //If there's no such case, ans1 will be empty and the graph can be treat as undirectional graph.
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            // A node has two parents
            if (parents[v] > 0) {
                ans1 = {parents[v], v};
                ans2 = edge;
                
                // Delete the later edge
                edge[0] = edge[1] = -1;
            }
            
            parents[v] = u;
        }
        
        for(const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Invalid edge (we deleted in step 1)
            if (u < 0 || v < 0) continue;
            
            if (!roots[u]) roots[u] = u;
            if (!roots[v]) roots[v] = v;
            int pu = find(u, roots);
            int pv = find(v, roots);
            
            // Both u and v are already in the tree
            if (pu == pv)
                return ans1.empty() ? edge : ans1;
            
            // Unoin, always merge smaller set (pv) to larger set (pu)
            if (sizes[pv] > sizes[pu])
                swap(pu, pv);
            
            roots[pv] = pu;
            sizes[pu] += sizes[pv];
        }
        
        return ans2;
    }
    
private:
    int find(int node, vector<int>& roots) {
        while (roots[node] != node) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }
};
