// https://leetcode.com/problems/circle-and-rectangle-overlapping/discuss/563463/C%2B%2B-with-simple-explanation
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // assuming moving circle to (0, 0), move rectangle accordingly 
        x1 -= x_center; x2 -= x_center;
        y1 -= y_center; y2 -= y_center;
        
        // check if there's any point (x, y) inside circle, it can be checked by x*x + y*y <= r*r
        // minX if both edge's x are on the same side(both >0, or both < 0), then pick the smaller one, 
        // otherwise, pick 0(since it will generate smallest x*x value)
        int minX = x1 * x2 > 0 ? min(x1*x1, x2*x2) : 0, minY = y1 * y2 > 0 ? min(y1*y1, y2*y2) : 0;
        return minY + minX <= radius * radius;
    }
};
