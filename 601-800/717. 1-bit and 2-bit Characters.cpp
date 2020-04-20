// https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/245994/C%2B%2B-3-lines-beats-100-with-explanation
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count_1 = 0;
        for (int i = (int) bits.size() - 2; i >= 0 && bits[i] == 1; i--) count_1++;
        return (count_1 % 2 == 0);
    }
};
