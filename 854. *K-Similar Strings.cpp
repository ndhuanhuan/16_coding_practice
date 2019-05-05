// https://blog.csdn.net/mrfive555/article/details/82811546
// https://blog.csdn.net/yecuandu1534/article/details/80747209


class Solution 
{
public:
    int kSimilarity(string A, string B) 
    {
        
        string tA,tB;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=B[i])
            {
                tA.push_back(A[i]);
                tB.push_back(B[i]);
            }
        }
        unordered_map<string,int> mp;//string距离目标字符串所需交换的次数
        return dfs(tA,tB,0,mp);
    }
    int dfs(string a,string b,int pos, unordered_map<string, int> &dp)
    {
        if(pos==b.size())
        {
            dp[a]=0;//此时a==b，交换次数为0.
            return 0;
        }
        if(dp.count(a)) return dp[a]; //交换到已经交换过的情况，不用重复计算了
        if(a[pos]==b[pos]) 
            return dfs(a,b,pos+1,dp);
        int mn=INT_MAX; //从当前的a换到b的全局最小值
        for(int i=pos+1;i<a.size();i++)
        {
            if(a[i]==b[pos]) //可以进行交换
            {
                swap(a[i],a[pos]);
                int dist=dfs(a,b,pos+1,dp);
               // if(dist!=-1) 
                mn=min(mn,dist+1);
                swap(a[i],a[pos]);//交换回来
            }
        }
        //if(mn==INT_MAX) return -1; 
        dp[a]=mn;
        return dp[a];
    }

};
