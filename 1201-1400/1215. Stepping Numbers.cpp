// https://leetcode.com/problems/stepping-numbers/discuss/397742/Short-C%2B%2B-solution-beat-100
constexpr auto res = []() {
    array<int, 3600> v{0,1,2,3,4,5,6,7,8,9};
    v.back() = INT_MAX;
    for (int i = 1, p = 10; p < v.size() - 1; i++) {
        int m1 = v[i] % 10 - 1, m2 = v[i] % 10 + 1;
        if (m1 >= 0)
            v[p++] = v[i] * 10 + m1;
        if (m2 <= 9)
            v[p++] = v[i] * 10 + m2;
    }
    return v;
}();
class Solution {
public:
	vector<int> countSteppingNumbers(int low, int high) {
		auto lb = lower_bound(res.begin(), res.end(), low);
		auto ub = upper_bound(res.begin(), res.end(), high);
		return vector<int>(lb, ub);
	}
};
