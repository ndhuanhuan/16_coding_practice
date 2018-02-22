//https://www.hrwhisper.me/leetcode-h-index-h-index-ii/
class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int n = citations.size();
		for (int i = 0; i < n; i++)
			if (citations[i] >= n - i)
				return n - i;
		return 0;
	}
};


//Better
//https://segmentfault.com/a/1190000003794831
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        vector<int> count(N+1,0);
	// 统计各个引用次数对应多少篇文章!
        for (int n : citations)
        {
            if (n > N)
                n = N;
            count[n]++;
        }
        int sum = 0;
        for (int i = N; i >= 0; i--)
        {
            sum += count[i];
	    //sum为到目前为止文章总数（且这些文章引用数肯定大于等于i）， i为引用数， 如果文章数大于等于引用数
		//由于是从大向小扫描，所以这个位置就是h index（sum逐渐增加，i逐渐减小）
            if (sum >= i)
                return i;
        }
        return 0;
    }
};
