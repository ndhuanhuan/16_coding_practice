//https://discuss.leetcode.com/topic/29006/c-java-python-binary-search-solution-with-explanation
//http://www.cnblogs.com/grandyang/p/5268775.html
//http://www.cnblogs.com/yrbbest/p/5050022.html


class Solution {
public:
    vector<vector<char>> *image;
int minArea(vector<vector<char>> &iImage, int x, int y) {
    image = &iImage;
    int m = int(image->size()), n = int((*image)[0].size());
    int top = searchRows(0, x, 0, n, true);
    int bottom = searchRows(x + 1, m, 0, n, false);
    int left = searchColumns(0, y, top, bottom, true);
    int right = searchColumns(y + 1, n, top, bottom, false);
    return (right - left) * (bottom - top);
}



int searchRows(int i, int j, int low, int high, bool opt) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && (*image)[mid][k] == '0') ++k;
        if (k < high == opt)         
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}


//for example, we are search for left. Then i=0, j=y, we are searching in the left part of the selected pixel.
//low=top, high= bottom, these are the row range we need to search.
// k<high==opt, if k<high which means, we found a black pixel, then we should still go more left to see whether there's a pixel.
//Otherwise, there's no black pixel in any row image[k][mid], k can be rows in range [low,top]. So there may be some black pixels more
//left than mid. But we don't care!!! becuase they are not connected with the selected pixel we care about.

int searchColumns(int i, int j, int low, int high, bool opt) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && (*image)[k][mid] == '0') ++k;
        if (k < high == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
    
};
