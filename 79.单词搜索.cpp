/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (45.27%)
 * Likes:    952
 * Dislikes: 0
 * Total Accepted:    189K
 * Total Submissions: 417.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

// @lc code=start
class Solution
{
private:
    int index = 0;
    bool backtracking(int r, int c, vector<vector<char>> &b, string &w)
    {
        if (b[r][c] != w[index])
            return false;
        if (index == w.size() - 1)
            return true;
        char temp = b[r][c];
        b[r][c] = 0;
        index++;
        if ((r > 0 && backtracking(r - 1, c, b, w)) || ((r < b.size() - 1) && backtracking(r + 1, c, b, w)) || (c > 0 && backtracking(r, c - 1, b, w) || (c + 1 < b[0].size() && backtracking(r, c + 1, b, w))))
            return true;
        b[r][c] = temp;
        index--;
        return false;
    }

public:
    bool exist(vector<vector<char>> &b, string w)
    {
        for (int i = 0; i < b.size(); i++)
        {
            for (int j = 0; j < b[0].size(); j++)
            {
                if (backtracking(i, j, b, w))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
