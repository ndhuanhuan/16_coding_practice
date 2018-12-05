class Solution {
    bool canfill(string & target, string & stamp, int i, int l)
    {
        bool all = 1;
        for(int j = 0; j < l; ++j)
        {
            if (target[i + j] == '?') continue;
            all = 0;
            if (target[i + j] != stamp[j]) return 0;
        }
        return !all;
    }
    
    void fill(string & target, int i, int l)
    {
        for(int j = 0; j < l; ++j)
        {
            target[i + j] = '?';
        }
    }
    
    bool done(string & target, int l)
    {
        for(int i = 0; i < l; ++i)
        {
            if (target[i] != '?') return 0;
        }
        return 1;
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size(), nn = n * 10;
        vector<int> ans;
        bool ok = 0;
        while(ans.size() <= nn)
        {
            bool has = 0;
            for(int i = 0; i + m <= n; ++i)
            {
                if (canfill(target, stamp, i, m))
                {
                    ans.push_back(i);
                    fill(target, i, m);
                    has = 1;
                }
            }
            
            if (done(target, n))
            {
                ok = 1;
                break;
            }
            
            if (!has) return {};
        }
        
        if (ok)
        {
            reverse(ans.begin(), ans.end());
            return ans; 
        }
        
        return {};
    }
};
