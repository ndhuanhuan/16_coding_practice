// https://leetcode.com/problems/minimize-rounding-error-to-meet-target/discuss/305837/C%2B%2B-greedy-O(NlogN)
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int _max{}, _min{}, c{}; 
        double err{}; 
        vector<double> dprices;
        for (auto& p : prices){
            dprices.push_back (stod(p));
            _max += static_cast<int> (ceil (dprices.back()) );
            _min += static_cast<int> (floor (dprices.back()) );
        }
        if ( target < _min || target > _max) return "-1";
        int round_ups = target - _min;
        sort (dprices.begin(), dprices.end(), [] (double d1, double d2){
            return  ceil (d1) - d1< ceil (d2) - d2;
        });
        for (int i = 0; i < dprices.size(); ++ i) {
            if (c < round_ups && ceil (dprices[i]) - dprices[i] != 0) {
               err += (ceil (dprices[i]) - dprices[i]); 
                c++; // from floor to ceil, diff is 1
            }
            else if (c >= round_ups) err += (dprices[i] - floor (dprices[i]) ); 
        }
        string s = to_string (err);
        return s.substr (0, s.find_first_of ('.', 0) + 4);
    }
};
