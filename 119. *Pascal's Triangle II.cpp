//http://www.cnblogs.com/grandyang/p/4031536.html
//那么我们只需要两个for循环，除了第一个数为1之外，后面的数都是上一次循环的数值加上它前面位置的数值之和，不停地更新每一个位置的值，便可以得到第n行的数字
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out;
        if (rowIndex < 0) return out;
        
        out.assign(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex; ++i) {
            if ( i == 0) {
                out[0] = 1;
                continue;
            }
            for (int j = rowIndex; j >= 1; --j) {
                out[j] = out[j] + out[j-1];
            }
        }
        return out;
    }
};
