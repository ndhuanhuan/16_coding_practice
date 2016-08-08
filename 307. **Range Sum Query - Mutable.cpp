//http://www.cnblogs.com/zichi/p/4806998.html
//http://www.cnblogs.com/grandyang/p/4985506.html
//http://blog.jobbole.com/96430/
//

class NumArray {
public:
    NumArray(vector<int> &nums) {
        num.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    void update(int i, int val) {
        int diff = val - num[i + 1];
        for (int j = i + 1; j < num.size(); j += (j&-j)) {
            bit[j] += diff;
        }
        num[i + 1] = val;
    }
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }    
    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> num;
    vector<int> bit;
};





class SegNode{
public:
    int start, end, sum;
    SegNode* left;
    SegNode* right;
    SegNode(int s, int e){
        start = s; end = e;
        sum = 0;
    }
};


//http://www.cnblogs.com/jcliBlogger/p/4989021.html
class NumArray {
private:
    SegNode* root;
    SegNode* buildTree(vector<int>& nums, int s, int e){
        if (s > e) return NULL;
        SegNode* node = new SegNode(s, e);
        if (s == e){
            node->sum = nums[s];
        }else{
           int mid = (s + e)/2;
           node->left = buildTree(nums, s, mid);
           node->right = buildTree(nums, mid+1, e);
           node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }
    
    int sumTree(int s, int e, SegNode* node){
        if (node->start == s && node->end == e) return node->sum;
        int mid = (node->start + node->end)/2;
        if (e <= mid)
            return sumTree(s, e, node->left);
        else if (s > mid)
            return sumTree(s, e, node->right);
        else
            return sumTree(s, mid, node->left) + sumTree(mid+1, e, node->right);
    }
    
    void updateTree(int i, int val, SegNode* node){
        if (node == NULL) return;
        if (node->start == node->end && node->start == i){
            node->sum = val;
            return;
        }
        int mid = (node->start + node->end)/2;
        if (i <= mid)
            updateTree(i, val, node->left);
        else
            updateTree(i, val, node->right);
        node->sum = node->left->sum + node->right->sum;
    }
    
public:
    NumArray(vector<int> &nums) {
        root = buildTree(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        updateTree(i, val, root);
    }

    int sumRange(int i, int j) {
        return sumTree(i, j, root);
    }
};
