/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.size() > b.size())
        {
            int k = b.size();
            for (int i = 0; i < a.size() - k; i++)
            {
                b.insert(0, 1, '0');
            }
        }
        else
        {
            if (b.size() > a.size())
            {
                int k = a.size();
                for (int i = 0; i < b.size() - k; i++)
                {
                    a.insert(0, 1, '0');
                }
            }
        }
        cout << b << endl;
        cout << a << endl;
        b.insert(0, 1, '0');
        a.insert(0, 1, '0');
        string t;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            t.insert(0, 1, a[i] + b[i] - '0');
        }
        cout << t << endl;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (t[i] == '2')
            {
                t[i - 1]++;
                t[i] = '0';
            }
            else if (t[i] == '3')
            {
                t[i - 1]++;
                t[i] = '1';
            }
        }
        if (t[0] == '0')
            t.erase(t.begin());
        return t;
    }
};
// @lc code=end
