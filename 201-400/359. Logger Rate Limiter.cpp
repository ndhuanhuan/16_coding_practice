//http://www.cnblogs.com/grandyang/p/5592635.html
class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < m[message]) return false;
        m[message] = timestamp + 10;
        return true;
    }

private:
    unordered_map<string, int> m;
};
