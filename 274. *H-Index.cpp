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
            if (sum >= i)
                return i;
        }
        return 0;
    }
};
