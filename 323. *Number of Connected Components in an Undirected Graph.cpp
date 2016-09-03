//
class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        root = vector<int>(n, -1);
        int size = edges.size();
        //int count = n;
        for(int i = 0; i < size; ++i)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            int uroot = findRoot(u);
            int vroot = findRoot(v);
            if(uroot != vroot)
            {
                //--count;
                unionSet(uroot, u, vroot, v);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (findRoot(i) == i)
                count++;
        }
        //return count;
        return count;
    }
private:
    void unionSet(int uroot, int u, int vroot, int v)
    {
        root[uroot] = vroot;
    }
    int findRoot(int u)
    {
        if(root[u] == -1) return u;
        root[u] = findRoot(root[u]);
        return root[u];
    }
private:
    vector<int> root;
    
};
