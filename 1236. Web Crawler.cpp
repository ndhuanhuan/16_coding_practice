// https://leetcode.com/problems/web-crawler/discuss/531170/Short-C%2B%2B-BFS
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        const string hostname = startUrl.substr(0, startUrl.find('/', 7));
        vector<string> q {startUrl};
        unordered_set<string> seen(q.cbegin(), q.cend());
        for (int i = 0; i < q.size(); ++i) {
            string url = q[i];
            for (auto& child : htmlParser.getUrls(url)) {
                if (child.find(hostname) == string::npos || seen.count(child)) continue;
                q.push_back(child);
                seen.insert(child);
            }
        }
        return q;
    }
};
