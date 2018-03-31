//http://zxi.mytechroad.com/blog/searching/leetcode-282-expression-add-operators/
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    string exp(num.length() * 2, '\0');    
    dfs(num, target, 0, exp, 0, 0, 0, &ans);
    return ans;
  }
private:
  void dfs(const string& num, const int target,
           int pos, string& exp, int len, long prev, long curr,
           vector<string>* ans) {    
    if (pos == num.length()) {      
      if (curr == target) ans->push_back(exp.substr(0, len));
      return;
    }
    
    long n = 0;
    int s = pos;
    int l = len;
    if (s != 0) ++len;    
    while (pos < num.size()) {      
      n = n * 10 + (num[pos] - '0');
      if (num[s] == '0' && pos - s > 0) break; // 0X... invalid number
      if (n > INT_MAX) break; // too long
      exp[len++] = num[pos++];
      if (s == 0) {
        dfs(num, target, pos, exp, len, n, n, ans);
        continue;
      }
      exp[l] = '+'; dfs(num, target, pos, exp, len, n, curr + n, ans);
      exp[l] = '-'; dfs(num, target, pos, exp, len, -n, curr - n, ans);
      exp[l] = '*'; dfs(num, target, pos, exp, len, prev * n, curr - prev + prev * n, ans);
    }
  }
};




//http://www.cnblogs.com/grandyang/p/4814506.html
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperatorsDFS(num, target, 0, 0, "", res);
        return res;
    }
    void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res) {
        if (num.size() == 0 && curNum == target) {
            res.push_back(out);
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if (out.size() > 0) {
                addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
            } else {
                addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
    }
};
