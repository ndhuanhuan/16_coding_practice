// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/discuss/648548/C%2B%2BPython-Simple-simulation-and-2-lines
class Solution {
public:
    //int isPrefixOfWord(string& sentence, string& searchWord) { // also ok
    int isPrefixOfWord(string sentence, string_view searchWord) {
        stringstream ss(sentence);
        string word;
        int i=1;
        while(ss>>word){
            if(word.find(searchWord) == 0 ) return i;
            i++;
        }
        return -1;
    }
};
