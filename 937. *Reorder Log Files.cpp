class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // use 'stable_sort' instead of the 'sort'
        std::stable_sort(logs.begin(), logs.end(), [](const std::string& lhs, const std::string& rhs) {
            auto i = lhs.find_first_of(' '), j = rhs.find_first_of(' ');
            bool digiti = isdigit(lhs[i+1]);
            bool digitj = isdigit(rhs[j+1]);
            return (!digiti && !digitj) ? lhs.substr(i+1) < rhs.substr(j+1) : !digiti;
        });
        
        return logs;
    }
};
