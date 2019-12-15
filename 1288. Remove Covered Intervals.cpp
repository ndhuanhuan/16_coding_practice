class Solution {
public:
    bool isSubsetOf(vector<int> & a , vector<int> & b){
        return (b[0] <= a[0] && b[1] >= a[1]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto thisway = [&](vector<int> a , vector<int> b){
            return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
        };
        sort(intervals.begin() , intervals.end(), thisway);
        vector<int> cur = intervals[0];
        int total = n;
        for(int i = 1; i < n; ++i){             
            if(isSubsetOf(intervals[i] , cur)){ 
                --total;                       
            }                                   
            else{                               
                cur = intervals[i];             
            }                                   
        }                                       
        return total;                           
    }
}; 
