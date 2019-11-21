// https://leetcode.com/problems/robot-room-cleaner/discuss/148751/Very-short-C%2B%2B-recursive-DFS-4ms
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> data;
    int x=0;
    int y=0;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    int dir=0;
    void cleanRoom(Robot& robot) {
        if(data[x][y]==1){
            return;
        }
        data[x][y]=1;
        robot.clean();
        for(int i=0; i<4; i++){
            if(robot.move()){
                x+=dx[dir];
                y+=dy[dir];
                cleanRoom(robot);
                robot.turnRight(); // Ticky: you need to move back to original spot since this is DFS, basically revert your moves.
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                x-=dx[dir];
                y-=dy[dir];
            }
            robot.turnRight();
            dir=(dir+1)%4;
        }
    }
};
