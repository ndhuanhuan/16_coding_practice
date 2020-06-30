// https://www.acwing.com/solution/LeetCode/content/381/
class Solution {
public:
    bool check(const string &s, const unordered_set<string> &v) {
        int L = s.size();
        vector<int> f(L + 1, INT_MIN);
        f[0] = 0;

        for (int i = 0; i < L; i++) {
            if (f[i] < 0)
                continue;

            for (int j = L; j > i; j--) {
                if (v.find(s.substr(i, j - i)) != v.end())
                    f[j] = f[i] + 1;

                if (f[L] > 1)
                    return true;
            }
        }

        return f[L] > 1;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> v(words.begin(), words.end());

        int n = words.size();
        for (const string &s : words)
            if (check(s, v))
                ans.push_back(s);

        return ans;
    }
};
