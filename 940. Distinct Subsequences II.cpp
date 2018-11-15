//https://leetcode.com/problems/distinct-subsequences-ii/discuss/192095/C%2B%2B-O(n)-or-O-(n)-Geeks4Geeks-improved-to-O(n)-or-O(1)
class Solution {
public:
    int distinctSubseqII(string S) {
    int pos[26] = {}, mod = 1e9 + 7, sum = 1;
    for (auto ch : S) {
        auto old_sum = sum;
        sum = (mod + sum * 2 % mod - pos[ch - 'a']) % mod;
        pos[ch - 'a'] = old_sum;
    } 
    return sum - 1; 
}  
};
