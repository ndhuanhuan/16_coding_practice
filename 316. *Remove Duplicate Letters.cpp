//https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/remove-duplicate-letters.cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> remaining;
        for (const auto& c : s) {
            ++remaining[c];
        }

        unordered_set<char> in_stack; //quick access to current stack(as we cannot random access stack)
        string stk;
        for (const auto& c : s) {
            if (!in_stack.count(c)) {
                while (!stk.empty() && stk.back() > c && remaining[stk.back()]) {  // remove all characters that larger than current chracter and still exist in following characters.  
                    in_stack.erase(stk.back());
                    stk.pop_back();
                }
                stk.push_back(c);
                in_stack.emplace(c);
            }
            --remaining[c];
        }
        return stk; 
        
    }
};
