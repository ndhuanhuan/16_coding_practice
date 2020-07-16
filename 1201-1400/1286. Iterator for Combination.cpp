// https://www.acwing.com/solution/LeetCode/content/7235/
class CombinationIterator {
public:
    vector<int> v;
    int len;
    string ch;
    bool nxt;

    CombinationIterator(string characters, int combinationLength) {
        ch = characters;
        len = combinationLength;
        v.resize(combinationLength);
        for (int i = 0; i < len; i++)
            v[i] = i;
        nxt = true;
    }

    string next() {
        string res;
        for (int i = 0; i < len; i++)
            res += ch[v[i]];

        int pos = -1;

        for (int i = len - 1; i >= 0; i--)
            if (v[i] + len - i < ch.length()) {
                pos = i;
                break;
            }

        if (pos != -1) {
            v[pos]++;
            for (int i = pos + 1; i < len; i++)
                v[i] = v[i - 1] + 1;
        } else {
            nxt = false;
        }

        return res;
    }

    bool hasNext() {
        return nxt;
    }
};
