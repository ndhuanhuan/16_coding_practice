// https://www.acwing.com/file_system/file/content/whole/index/content/1087252/
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = positions.size();
        double eps = 1e-8;
        double x, y;
        double sum_x = 0, sum_y = 0;
        for (int i = 0; i < n; ++i) {
            sum_x += positions[i][0];
            sum_y += positions[i][1];
        }
        x = sum_x / n, y = sum_y / n;
        double pre_x = x, pre_y = y;

        while (true) {
            double sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < n; ++i) {
                double tmp = dis(x, y, positions[i][0], positions[i][1]);
                if (tmp < eps) continue;
                sum1 += (double)positions[i][0] / tmp;
                sum2 += (double)positions[i][1] / tmp;
                sum3 += (double)1 / tmp;
            }
            if (sum3 < eps) break;

            pre_x = x, pre_y = y;
            x = sum1 / sum3, y = sum2 / sum3;
            if (abs(x - pre_x) < eps && abs(y - pre_y) < eps) break;
        }

        double res = 0;
        for (auto & e : positions) res += dis(x, y, e[0], e[1]);

        return res;
    }

    inline double dis(double x1, double y1, double x2, double y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};
