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


//Better one

class Solution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);
        
        int maxidx = -1; 
        int maxdigit = -1;
        int leftidx = -1;
        int rightidx = -1;
        
        for (int i = numstr.size() - 1; i >= 0; --i) {
            // current digit is the largest by far
            if (numstr[i] > maxdigit) {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap if there is no more 
            // such situation on the left side
            if (numstr[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        // num is already in order
        if (leftidx == -1) return num;

        swap(numstr[leftidx], numstr[rightidx]);

        return stoi(numstr);
    }
};
