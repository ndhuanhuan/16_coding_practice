// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/discuss/419772/C%2B%2B-beats-100-w-explanation
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int a = 0 , b = 0;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] == 'x' && s2[i] == 'y'){
                a++;
            }
            else if(s1[i] == 'y' && s2[i] == 'x'){
                b++;
            }
            
        }
        if((a+b) % 2 != 0){
            return -1;
        }
        if(a % 2 == 0){
            return a / 2 + b / 2;  // This means we can apply 1-swap for all pairs
        }
        else{
            return a / 2 + b / 2 + 2; // This means we can partially apply 1-swap, but we need to use 2-swap ONCE since there is 1 pair of {xy,yx}
        }
        
    }
};
