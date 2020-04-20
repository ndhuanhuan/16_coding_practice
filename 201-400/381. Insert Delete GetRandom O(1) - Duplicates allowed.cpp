//http://www.cnblogs.com/grandyang/p/5756148.html
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].push(nums.size());
        nums.push_back(val);
        return m[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m[val].empty()) return false;
        int idx = m[val].top();
        m[val].pop();
        if(nums.size()-1!=idx)
        {
            int t = nums.back();
            nums[idx] = t;
            m[t].pop();
            m[t].push(idx);
            
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
         return nums[rand() % nums.size()];
    }
    private:
        vector<int> nums;
        unordered_map<int, priority_queue<int>> m;
};
