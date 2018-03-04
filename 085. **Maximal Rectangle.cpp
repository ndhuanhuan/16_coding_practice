//http://www.cnblogs.com/TenosDoIt/p/3454877.html
//http://www.cnblogs.com/grandyang/p/4322667.html
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        vector<int> height;
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] <= height[i]) s.push(i);
            else {
                int tmp = s.top();
                s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }
};

//Preferred
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') ++height[j];
                else height[j] = 0;
            }
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else {left[j] = 0; cur_left = j + 1;}
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}
            }
            for (int j = 0; j < n; ++j) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};
