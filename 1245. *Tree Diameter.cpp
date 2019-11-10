// https://leetcode.com/problems/tree-diameter/discuss/420452/C%2B%2B-with-picture-O(n)
// longest diameter is the top two path sum up
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {        
        const int n = edges.size();
        vector<vector<int>> g(n+1);
        for(const auto& e: edges){
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        int res = 0;
        vector<int> seen(n+1, 0);
        dfs(g, seen, 0, res);
        return res;
    }
    
private:
    // diameter: global maximum
    // cur: current node
   //  returned value: the longest depth of the node 'cur'
    int dfs(vector<vector<int>>& g, vector<int>& seen, int cur, int& diameter){
        seen[cur]=1;
        int depth_longest = 0; // local maximum to 'cur' by far, or maximum depth before 'next'
        for(const auto& next: g[cur]){ // next: neighbor/child of 'cur'
            if(seen[next]) continue;
            int depth_next = dfs(g, seen, next, diameter);
            diameter = max(diameter, depth_next + depth_longest);
            depth_longest = max(depth_longest, depth_next);
        }
        return depth_longest + 1;
    }
};
