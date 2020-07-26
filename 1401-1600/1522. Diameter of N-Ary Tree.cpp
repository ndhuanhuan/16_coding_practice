// https://leetcode.com/problems/diameter-of-n-ary-tree/discuss/755397/C%2B%2B-simple-DFS-92
class Solution {
public:
    int diameter(Node* root) {
        int max = 0;
        dfs(root, max);
        return max - 1;
    }
    
    int dfs(Node* root, int& max_)  {
        if(!root) return 0;
        int max1 = 0, max2 = 0; //max1 largest
        for(auto& child: root->children) {
            int len = dfs(child, max_);
            if(len > max1) {
                max2 = max1;
                max1 = len;
            } else if(len > max2) {
                max2 = len;
            }
        }
        
        max_ = max(max_, max1 + max2 + 1);
        return max(max1+1, max2+1);
    }
};
