class TweetCounts {
public:
    unordered_map<string,multiset<int>>m;
    vector<int>res;
    TweetCounts() {
        m.clear();
        // m=unordered_map<string, set<int>>();
    }
    
    void recordTweet(string tweet, int time) {
        m[tweet].insert(time);
        return ;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweet, int startTime, int endTime) {
        // vector<int>res=vector<int>();
        res.clear();
        int gap=60;
        if(freq=="hour") gap=3600;
        else if(freq=="day") gap=86400;
        for(int i=startTime;i<endTime+1;i+=gap){
            auto it=m[tweet].lower_bound(i);
            int val=0;
            for(;it!=m[tweet].end() && *it<min(endTime+1, i+gap);it++){
                // cout<<"time: "<<*it<<endl;
                val++;
            } 
            // cout<<"val: "<<val<<endl;
            res.push_back(val);
        }
        return res;
    }
    
};
