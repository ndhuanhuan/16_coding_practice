class Solution {
public:
    string toHexspeak(string num) {
        auto n = stol(num);
        stringstream st;
        st << hex << uppercase  << n;
        string s(st.str());
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] > '1' && s[i] <= '9') return "ERROR";
            if (s[i] == '0') s[i] = 'O';
            if (s[i] == '1') s[i] = 'I';
        }
        return s;
    }
};
