// https://zxi.mytechroad.com/blog/greedy/leetcode-885-boats-to-save-people/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(), people.rend());
        int i = 0;
        int j = people.size() - 1;
        int ans = 0;
        while(i <= j) {
            ++ans;
            if(i == j ) break;
            if(people[i++] + people[j] <= limit) --j;
        }
        return ans;
    }
};
