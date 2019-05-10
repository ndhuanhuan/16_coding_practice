// https://leetcode.com/problems/rectangle-overlap/discuss/132340/C%2B%2BJavaPython-1-line-Solution-1D-to-2D
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
         return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
};
