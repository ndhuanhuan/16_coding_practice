// https://blog.csdn.net/yuweiming70/article/details/80639361
class Solution {
public:
    long long binji(vector<int> &xs)
    {
        int n=xs.size()/2;
        long long ans=0;
        vector<int> all_x(xs);
        sort(all_x.begin(),all_x.end());
        all_x.erase(unique(all_x.begin(), all_x.end()), all_x.end());//所有的x排序去重，得到了一系列最小的区间
        
        for(int i=0;i<all_x.size()-1;i++)
        {
            int lo=all_x[i],hi=all_x[i+1];//对于一个极小区间来说，遍历一次xs，有的话加上去
            for(int j=0;j<n;j++)
            {
                if(xs[2*j]<=lo && hi<=xs[2*j+1])
                {
                    ans += hi-lo;
                    break;//已经在了，不必算其他的区间
                }
            }
        }
        return ans;
    }
    long long in_delta_y_area(vector<vector<int>>& rectangles,int y_min,int y_max)
        //夹在y一定范围内的矩形的x都要加入一个列表，然后求出这些x的最大最小值
    {
        int n = rectangles.size();
        vector<int> xs;//所有矩形在y范围内的那些x1x2们
        for(int i=0;i<n;i++)
        {
            int x1=rectangles[i][0],y1=rectangles[i][1],x2=rectangles[i][2],y2=rectangles[i][3];
            if(y1<=y_min && y_max<=y2)
            {
                xs.push_back(x1);
                xs.push_back(x2);
            }
        }
        if(xs.size()==0)
            return 0;
        
        long long sum_x =binji(xs);//对于这些x1x2的集合，求出集合并集覆盖区间
        return sum_x*(long long)abs((long long)y_max-(long long)y_min);
    }
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        int n = rectangles.size();
        vector<int> all_y;//找到所有的y
        for(int i=0;i<n;i++)
        {
            all_y.push_back(rectangles[i][1]);
            all_y.push_back(rectangles[i][3]);
        }
        sort(all_y.begin(),all_y.end());
        all_y.erase(unique(all_y.begin(), all_y.end()), all_y.end());//排序去重，得到最小的y的分割
        
        long long ans=0;
        for(int i=0;i<all_y.size()-1;i++)
            ans += in_delta_y_area(rectangles,all_y[i],all_y[i+1]);//每个y的小区间都求一次x方向上的矩形之和
        
        return ans % 1000000007;
    }

};
