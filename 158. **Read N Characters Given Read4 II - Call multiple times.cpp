//http://www.cnblogs.com/grandyang/p/5181672.html
// Forward declaration of the read4 API.
int read4(char *buf);  //this guy will always read from buffs begining, so the challenge is that we'll call read multiple times, where is the beginning of read

//read4 会把读出来的字符存进buf里（char *buf），这点要记住。
//所以我们是read4(buff)

class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            //Proceed 4 characters every time we already proceeded all 4 characters
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
private:
    int readPos = 0, writePos = 0;
    char buff[4];
};
