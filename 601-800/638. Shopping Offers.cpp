// https://leetcode.com/problems/shopping-offers/discuss/105252/Concise-c%2B%2B-DFS-solution-6ms
bool operator> (const vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); ++i)
        if(a[i] < b[i]) return false;
    return true;
}

int operator* (const vector<int>& a, const vector<int>& b) {
    int res = 0;
    for(int i = 0; i < a.size(); ++i)
        res += a[i] * b[i];
    return res;
}

void operator+= (vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); ++i)
        a[i] += b[i];
    return;
}
void operator-= (vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); ++i)
        a[i] -= b[i];
    return;
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int cost = needs * price;
        for(auto& spe: special) {
            if(spe.back() > cost) continue;
            if(needs > spe) {
                needs -= spe;
                cost = min(cost, spe.back() + shoppingOffers(price, special, needs));
                needs += spe;
            }
        }
        return cost;
    }
};
