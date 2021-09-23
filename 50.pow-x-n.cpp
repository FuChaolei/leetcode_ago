// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem50.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (37.64%)
 * Likes:    709
 * Dislikes: 0
 * Total Accepted:    205.1K
 * Total Submissions: 544.8K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 2.00000, n = 10
 * 输出：1024.00000
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 2.10000, n = 3
 * 输出：9.26100
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -100.0 
 * -2^31 
 * -10^4 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        return N >= 0 ? quickp(x, N) : 1 / quickp(x, -N);
    }

private:
    double quickp(double x, long long N)
    {
        if (N == 0)
            return 1;
        double y = quickp(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
};
//迭代
// class Solution
// {
// public:
//     double myPow(double x, int n)
//     {
//         double res = 1;
//         long long N = n;
//         if (n < 0)
//         {
//             N = -N;
//             x = 1 / x;
//         }
//         while (N)
//         {
//             if (N % 2 == 1)
//             {
//                 res *= x;
//             }
//             if(N!=1)
//             x *= x;
//             N /= 2;
//         }
//         return res;
//     }
// };
//暴力TLE
// class Solution
// {
// public:
//     double myPow(double x, int n)
//     {
//         long long N = n;
//         if(N<0){
//             x = 1 / x;
//             N = -N;
//         }
//         double ans = 1;
//         for (long long i = 0; i < N;i++)
//             ans *= x;
//         return ans;
//     }
// };
// @lc code=end
