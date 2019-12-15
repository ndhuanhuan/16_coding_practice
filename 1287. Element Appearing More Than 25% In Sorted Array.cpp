
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int gap=ceil(n/4);
        for(int x=0;x<n;x++){
            if(arr[x]==arr[x+gap])
                return arr[x];
        }
        return -1;//should not hit here ...
    }
};
