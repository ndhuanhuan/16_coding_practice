
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int mapping[26];
        char first;
        for(int i = 0; i < keyboard.size(); ++i) {
            if(i == 0) {
                first = keyboard[0];
            }
            mapping[keyboard[i] - 'a'] = i;
        }
        int result = 0, prev = 0;
        for(char & c : word) {
            result += abs(prev - mapping[c - 'a']);
            prev = mapping[c - 'a'];
        }
        return result;
    }
};
