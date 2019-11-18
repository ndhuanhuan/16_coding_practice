class Solution {
public:
    string encode(int num) {
        auto s = std::bitset< 64 >( num + 1 ).to_string();
        return s.substr(s.find('1') + 1);
    }
};
