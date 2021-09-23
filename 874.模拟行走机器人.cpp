/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 *
 * https://leetcode-cn.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Easy (41.21%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 45.7K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * 机器人在一个无限大小的 XY 网格平面上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令 commands
 * ：
 * 
 * 
 * -2 ：向左转 90 度
 * -1 ：向右转 90 度
 * 1  ：向前移动 x 个单位长度
 * 
 * 
 * 在网格上有一些格子被视为障碍物 obstacles 。第 i 个障碍物位于网格点  obstacles[i] = (xi, yi) 。
 * 
 * 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续尝试进行该路线的其余部分。
 * 
 * 返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。（即，如果距离为 5 ，则返回 25 ）
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 北表示 +Y 方向。
 * 东表示 +X 方向。
 * 南表示 -Y 方向。
 * 西表示 -X 方向。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：commands = [4,-1,3], obstacles = []
 * 输出：25
 * 解释：
 * 机器人开始位于 (0, 0)：
 * 1. 向北移动 4 个单位，到达 (0, 4)
 * 2. 右转
 * 3. 向东移动 3 个单位，到达 (3, 4)
 * 距离原点最远的是 (3, 4) ，距离为 3^2 + 4^2 = 25
 * 
 * 示例 2：
 * 
 * 
 * 输入：commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * 输出：65
 * 解释：机器人开始位于 (0, 0)：
 * 1. 向北移动 4 个单位，到达 (0, 4)
 * 2. 右转
 * 3. 向东移动 1 个单位，然后被位于 (2, 4) 的障碍物阻挡，机器人停在 (1, 4)
 * 4. 左转
 * 5. 向北走 4 个单位，到达 (1, 8)
 * 距离原点最远的是 (1, 8) ，距离为 1^2 + 8^2 = 65
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * commands[i] is one of the values in the list [-2,-1,1,2,3,4,5,6,7,8,9].
 * 0 
 * -3 * 10^4 i, yi 
 * 答案保证小于 2^31
 * 
 * 
 */

// @lc code=start
// #include<utility>//pair的头文件
// #include<set>//set的头文件
// class Solution {
// public:
//     int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//         int direx[] = {0,1,0,-1};
//         int direy[] = {1,0,-1,0};
//         int curx=0,cury=0;
//         int curdire = 0;
//         int comLen = commands.size();
//         int ans = 0;
//         set<pair<int, int>> obstacleSet;
//         for(int i=0;i<obstacles.size();i++)
//             obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));

//         for(int i=0;i<comLen;i++){
//             if(commands[i] == -1){  // -1：向右转 90 度
//                 curdire = (curdire + 1) % 4;
//             }else if(commands[i] == -2){  // -2：向左转 90 度
//                  curdire = (curdire + 3) % 4;
//             }else{  //  1 <= x <= 9：向前移动 x 个单位长度
//                 for(int j=0;j<commands[i];j++){
//                     //试图走出一步，并判断是否遇到了障碍物，
//                     int nx = curx + direx[curdire];
//                     int ny = cury + direy[curdire];
//                     //当前坐标不是障碍点，计算并与存储的最大欧式距离的平方做比较
//                     if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
//                         curx = nx;
//                         cury = ny;
//                         ans = max(ans, curx*curx + cury*cury);
//                     }else{
//                         //是障碍点，被挡住了，停留，只能等待下一个指令，那可以跳出当前指令了
//                         break;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution
{
public:
    int robotSim(vector<int> &c, vector<vector<int>> &o)
    {
        set<pair<int, int>> st;
        for (int i = 0; i < o.size(); i++)
        {
            st.insert(make_pair(o[i][0], o[i][1]));
        }
        vector<int> cx{0, 1, 0, -1};
        vector<int> cy{1, 0, -1, 0};
        int dic = 0;
        int res = 0;
        int x = 0, y = 0;
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] == -1)
                dic = (dic + 1) % 4;
            else if (c[i] == -2)
                dic = (dic + 3) % 4;
            else
            {
                for (int j = 1; j <= c[i]; j++)
                {
                    int tx = x + cx[dic];
                    int ty = y + cy[dic];
                    if (st.find(make_pair(tx, ty)) == st.end())
                    {
                        x = tx;
                        y = ty;
                    }
                    else
                    {
                        break;
                    }
                }
                res = max(res, x * x + y * y);
            }
        }
        return res;
    }
};
// @lc code=end
