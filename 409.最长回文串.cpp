/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        sort(s.begin(), s.end());
        int t = 0, i, j, a = 0;
        //cout<<s<<endl;
        for (i = 0; i < s.size() - 1; ++i)
        {
            //cout<<"i="<<i<<endl;
            char k = s[i];
            for (j = i + 1; k == s[j]; ++j)
            {
                //cout<<"j="<<j<<endl;
                t++;
            }
            if ((t + 1) % 2 == 0)
                a += t + 1;
            else
                a += t;
            i = j - 1;
            t = 0;
        }
        if (s.size() > a)
            a++;
        return a;
    }
};
// @lc code=end
