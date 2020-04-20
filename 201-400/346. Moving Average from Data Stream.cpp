class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum=0;
    }
    
    double next(int val) {
        if(q.size()>=size)
        {
            sum-=q.front();
            q.pop();
        }
        q.push(val);
        sum+=val;
        return sum*1.0/q.size();
    }
private:
    int size;
    double sum;
    queue<int> q;
};
