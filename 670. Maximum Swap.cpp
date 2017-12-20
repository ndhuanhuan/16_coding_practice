//http://www.cnblogs.com/grandyang/p/7583875.html
class Solution {
public:
    int maximumSwap(int num) {
        string res = to_string(num);
        string back = res;
        
        for(int i=res.size()-2; i>=0; --i) {
            back[i] = max(back[i], back[i + 1]);
        }
        
        for(int i=0; i<res.size(); i++) {
            if(res[i] == back[i]) continue;
            for (int j = res.size() - 1; j > i; --j) {
                if (res[j] == back[i]) {
                    swap(res[i], res[j]);
                    return stoi(res);
                }
            }
        }
        
        return stoi(res);
    }
};
