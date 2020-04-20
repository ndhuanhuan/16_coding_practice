
class Solution {
public:
    int numDigits(int num) {
        int n_digits = 0;
        while(num) {
            n_digits += 1;
            num /= 10;
        } 
        return n_digits;
    }
    
    int findNumbers(vector<int>& nums) {
        int even_digit_nums = 0;
        for(const int& num: nums)
            if(numDigits(num) % 2 == 0)
                ++even_digit_nums;
        
        return even_digit_nums;
    }
};
