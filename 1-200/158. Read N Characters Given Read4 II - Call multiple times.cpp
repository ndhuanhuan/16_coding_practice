// better explain: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/discuss/49607/The-missing-clarification-you-wish-the-question-provided
class Solution {
private:
    int bp = 0;
    int len = 0;
    char buffer[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while(i < n) {
            if(bp == len) {
                bp = 0;
                len = read4(buffer);
                if(len == 0) {
                    break;
                }
            }
            
            buf[i++] = buffer[bp++]; 
        }
        
        return i;
    }
};


//http://www.cnblogs.com/grandyang/p/5181672.html
class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;  // I think this is wrong, it can be smaller than n
    }
private:
    int readPos = 0, writePos = 0;
    char buff[4];
};
