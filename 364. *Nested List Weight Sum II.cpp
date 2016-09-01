//http://www.cnblogs.com/grandyang/p/5615583.html
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res=0;
        vector<int> v;
        for(auto a:nestedList)
        {
            helper(a,0,v);
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            res += v[i] * (v.size() - i);
        }
        return res;
    }
    
    void helper(NestedInteger ni, int depth, vector<int>& v)
    {
        if(depth>=v.size()) v.resize(depth+1);
        if(ni.isInteger())
        {
            v[depth]+=ni.getInteger();
        }
        else {
            for (auto a : ni.getList()) {
                helper(a, depth + 1, v);
            }
        }
    }
    
    
    
};
