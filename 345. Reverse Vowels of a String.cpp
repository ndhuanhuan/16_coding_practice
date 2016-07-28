class Solution {
public:
    string reverseVowels(string s) 
    {
       for (int i = 0, j = s.length() - 1; i < j;) {
            if (!is_vowel(tolower(s[i]))) {
                ++i;
            } else if (!is_vowel(tolower(s[j]))) {
                --j;
            } else {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
    
    const string vovel = "aeiou";
    bool is_vowel(char a)
    {
        return vovel.find(a) != string::npos;
    }
};
