/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution
{
public:
    int minMoves2(vector<int> &num)
    {

        int t, s = 0;
        sort(num.begin(), num.end());
        t = num[num.size() / 2];
        //cout<<t<<endl;
        for (int i = 0; i < num.size(); i++)
        {
            int k = abs(t - num[i]);
            //cout<<k<<endl;

            s += k;
        }

        return s;
    }
};
// @lc code=end
