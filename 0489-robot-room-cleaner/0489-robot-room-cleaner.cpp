/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<vector<int>> vec = {{-1,0},{0,1},{1,0},{0,-1}};
    set<pair<int,int>>visi;
    void go_back(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    void find(int row,int col, int dir, Robot& robot){
        visi.insert(make_pair(row,col));
        robot.clean();
        for(int i=0;i<4;i++){
            int new_dir = (dir+i)%4;
            int a=row+vec[new_dir][0],b=col+vec[new_dir][1];
            if(visi.find(make_pair(a,b)) == visi.end() && robot.move()){
                find(a,b,new_dir,robot);
                go_back(robot);
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        find(0,0, 0,robot);
    }
};