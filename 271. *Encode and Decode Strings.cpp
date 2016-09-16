//http://www.cnblogs.com/grandyang/p/5265628.html
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            auto found = s.find("/", i);
            int len = atoi(s.substr(i, found).c_str());
            res.push_back(s.substr(found + 1, len));
            i = found + len + 1;
        }
        return res;
    }
};
