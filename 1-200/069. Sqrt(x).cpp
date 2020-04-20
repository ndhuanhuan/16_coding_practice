//http://www.cnblogs.com/grandyang/p/4346413.html
// Binary Search
class Solution {
public:
    int sqrt(int x) {
        long long left = 0, right = (x / 2) + 1;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};

//Newton
class Solution {
public:
    int mySqrt(int x) {
        long res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};
