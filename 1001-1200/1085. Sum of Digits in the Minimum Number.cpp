
class Solution {
public:
    int sumOfDigits(vector<int>& v) 
    {
        int mini=v[0];
        for(int i=1;i<v.size();i++)
            mini=min(mini,v[i]);
        int sum=0;
        while(mini>0)
        {
            sum+=(mini%10);
            mini/=10;
        }
        return (sum&1 ? 0 : 1);
    }
};
