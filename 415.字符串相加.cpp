/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string a, string b)
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
        //cout<<b<<endl;
        //cout<<a<<endl;
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
            //cout<<t[i]<<endl;
            if (t[i] >= '9' + 1)
            {
                t[i - 1]++;
                t[i] = t[i] - 10;
            }
        }
        if (t[0] == '0')
            t.erase(t.begin());
        return t;
    }
};
// @lc code=end
