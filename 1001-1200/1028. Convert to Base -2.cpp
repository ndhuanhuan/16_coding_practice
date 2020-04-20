// https://www.geeksforgeeks.org/convert-number-negative-base-representation/
//n = (?negBase) * quotient + remainder 
//  = (?negBase) * (quotient + 1) + (remainder - negBase). 
class Solution {
public:
    string baseNeg2(int N) {
        return toNegativeBase(N, -2);
    }
    
    string toNegativeBase(int n, int negBase) 
    { 
        //  If n is zero then in any base it will be 0 only 
        if (n == 0) 
            return "0"; 

        string converted = ""; 
        while (n != 0) 
        { 
            // Get remainder by negative base, it can be 
            // negative also 
            int remainder = n % negBase; 
            n /= negBase; 

            // if remainder is negative, add abs(base) to 
            // it and add 1 to n 
            if (remainder < 0) 
            { 
                remainder += (-negBase); 
                n += 1; 
            } 

            // convert remainder to string add into the result 
            converted = to_string(remainder) + converted; 
        } 

        return converted; 
    } 
};
