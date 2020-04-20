class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        int left = 0;
        int right = len-1;
        string res=s;
        while(left<right)
        {
            swap(res[left],res[right]);
            left++;
            right--;
        }
        return res;
    }
};
