//http://www.cnblogs.com/grandyang/p/7829169.html
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, string> root;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> m;
        
        //首先我们遍历每个账户和其中的所有邮箱，先将每个邮箱的root映射为其自身，然后将owner赋值为用户名。
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                root[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }
        
        //然后开始另一个循环，遍历每一个账号，首先对帐号的第一个邮箱调用find函数，
        //得到其父串p，然后遍历之后的邮箱，对每个遍历到的邮箱先调用find函数，
        //将其父串的root值赋值为p，这样做相当于将相同账号内的所有邮箱都链接起来了。
        for (auto account : accounts) {
            string p = find(account[1], root);
            for (int i = 2; i < account.size(); ++i) {
                root[find(account[i], root)] = p;
            }
        }
        
        //我们下来要做的就是再次遍历每个账户内的所有邮箱，先对该邮箱调用find函数，
        //找到父串，然后将该邮箱加入该父串映射的集合汇总，这样就我们就完成了合并。
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                m[find(account[i], root)].insert(account[i]);
            }
        }
        
        //最后只需要将集合转为字符串数组，加入结果res中，
        //通过owner映射找到父串的用户名，加入字符串数组的首位置
        for (auto a : m) {
            vector<string> v(a.second.begin(), a.second.end());
            v.insert(v.begin(), owner[a.first]);
            res.push_back(v);
        }
        return res;
    }
    string find(string s, unordered_map<string, string>& root) {
        return root[s] == s ? s : find(root[s], root);
    }
};
