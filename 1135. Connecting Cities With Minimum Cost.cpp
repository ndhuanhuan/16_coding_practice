// https://leetcode.com/problems/connecting-cities-with-minimum-cost/discuss/374051/Clean-C%2B%2B-union-find-Solution
// https://leetcode.com/problems/connecting-cities-with-minimum-cost/discuss/345548/C%2B%2B-UF
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<int> parent(N+1,0);
        //sort by cost
        sort(connections.begin(),connections.end(),[](const vector<int>& a,const vector<int>& b){
           return b[2] > a[2]; 
        });
        iota(parent.begin(),parent.end(),0);
        int count = 1, sum =0;
        for(auto edge: connections)
        {
            auto a = find(edge[0],parent);
            auto b = find(edge[1],parent);
            if(a!=b)
            {
                sum+=edge[2];
                parent[b] = a;
                count++;
                //exits after edges have been connected
                if(count==N)
                {
                    return sum;
                }
            }
        }
        return -1;
    }
    
    int find(int a,vector<int>& parent)
    {
        if(a!=parent[a])
        {
            parent[a] = find(parent[a],parent);
        }
        return parent[a];
    }
};
