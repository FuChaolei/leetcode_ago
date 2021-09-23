/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 *
 * https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (41.90%)
 * Likes:    612
 * Dislikes: 0
 * Total Accepted:    47.1K
 * Total Submissions: 112.4K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于
 * nums[i] 的元素的数量。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [5,2,6,1]
 * 输出：[2,1,1,0] 
 * 解释：
 * 5 的右侧有 2 个更小的元素 (2 和 1)
 * 2 的右侧仅有 1 个更小的元素 (1)
 * 6 的右侧有 1 个更小的元素 (1)
 * 1 的右侧有 0 个更小的元素
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=star
//暴力TLE
// class Solution
// {
// public:
//     vector<int> countSmaller(vector<int> &nums)
//     {
//         int n = nums.size();
//         if (n == 0)
//             return {};
//         vector<int> res(n, 0);
//         for (int i = n - 2; i >= 0; i--)
//         {
//             int t = 0;
//             for (int j = n - 1; j > i; j--)
//             {
//                 if (nums[j] < nums[i])
//                 {
//                     t++;
//                 }
//             }
//             res[i] = t;
//         }
//         return res;
//     }
// };
//暴力优化:TLE
// class Solution
// {
// public:
//     vector<int> countSmaller(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> res(n), t;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             auto it = lower_bound(t.begin(), t.end(), nums[i]);
//             int pos = it - t.begin();
//             t.insert(it, nums[i]);
//             res[i] = pos;
//         }
//         return res;
//     }
// };
//二叉排序树:TLE
// struct BSTNode
// {
//     int val;
//     BSTNode *left;
//     BSTNode *right;
//     int count;
//     int left_count;
//     BSTNode(int val) : count(1), val(val), left_count(0), left{nullptr}, right{nullptr} {}
//     ~BSTNode()
//     {
//         delete left;
//         delete right;
//     }
//     int less_or_equal() const
//     {
//         return left_count + count;
//     }
// };
// class Solution
// {
// public:
//     vector<int> countSmaller(vector<int> &nums)
//     {
//         if (nums.empty())
//         {
//             return {};
//         }
//         std::reverse(nums.begin(), nums.end());
//         std::unique_ptr<BSTNode> root(new BSTNode(nums[0]));
//         vector<int> res{0};
//         for (int i = 1; i < nums.size(); i++)
//         {
//             res.emplace_back(insert(root.get(), nums[i]));
//         }
//         std::reverse(res.begin(), res.end());
//         return res;
//     }

// private:
//     int insert(BSTNode *root, int val)
//     {
//         if (root->val == val)
//         {
//             ++root->count;
//             return root->left_count;
//         }
//         else if (root->val > val)
//         {
//             ++root->left_count;
//             if (root->left == nullptr)
//             {
//                 root->left = new BSTNode(val);
//                 return 0;
//             }
//             return insert(root->left, val);
//         }
//         else
//         {
//             if (root->right == nullptr)
//             {
//                 root->right = new BSTNode(val);
//                 return root->less_or_equal();
//             }
//             return root->less_or_equal() + insert(root->right, val);
//         }
//     }
// };
//树状数组
// class FenwickTree
// {
// private:
//     vector<int> nums;
//     int lowbit(int n)
//     {
//         return n & -n;
//     }

// public:
//     FenwickTree(int n) : nums(n + 1, 0) {}
//     void update(int i, int del)
//     {
//         while (i < nums.size())
//         {
//             nums[i] += del;
//             i += lowbit(i);
//         }
//     }
//     int query(int i)
//     {
//         int sum = 0;
//         while (i > 0)
//         {
//             sum += nums[i];
//             i -= lowbit(i);
//         }
//         return sum;
//     }
// };
// class Solution
// {
// public:
//     vector<int> countSmaller(vector<int> &nums)
//     {
//         FenwickTree tree(nums.size());
//         vector<int> res;
//         set<int> st(nums.begin(), nums.end());
//         unordered_map<int, int> rank;
//         int t = 0;
//         for (auto it : st)
//         {
//             rank[it] = ++t;
//         }
//         for (int i = nums.size() - 1; i >= 0; i--)
//         {
//             res.emplace_back(tree.query(rank[nums[i]] - 1));
//             tree.update(rank[nums[i]], 1);
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };
//归并排序
// class Solution
// {
// public:
//     vector<int> countSmaller(vector<int> &nums)
//     {

//     }
// };
//归并排序
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
    }
};
// class Solution
// {
// public:
//     vector<pair<int, int>> a; // 待排序的数组
//     vector<pair<int, int>> b; // 归并排序辅助数组
//     vector<int> ans;
//     vector<int> countSmaller(vector<int> &nums)
//     {
//         if (nums.empty())
//             return {};

//         int n = nums.size();
//         ans = vector<int>(n);
//         b = vector<pair<int, int>>(n);

//         for (int i = 0; i < n; i++)
//             a.push_back({nums[i], i});

//         merge_sort(a, 0, n - 1);
//         return ans;
//     }
//     void merge_sort(vector<pair<int, int>> &a, int l, int r)
//     {
//         if (l == r)
//             return;
//         int mid = l + r >> 1;

//         merge_sort(a, l, mid);
//         merge_sort(a, mid + 1, r);

//         int i, j, k = 0;
//         for (i = l, j = mid + 1; i <= mid && j <= r;)
//         {
//             if (a[i].first <= a[j].first)
//             {
//                 b[k++] = a[i];
//                 ans[a[i++].second] += j - mid - 1; // 加上已经排在 a[i] 前面的数（在后面那个区间的数）
//             }
//             else
//                 b[k++] = a[j++];
//         }

//         while (i <= mid)
//         {
//             ans[a[i].second] += r - mid; // 加上所有的第二个区间的数的数量
//             b[k++] = a[i++];
//         }
//         while (j <= r)
//             b[k++] = a[j++];

//         for (int i = 0; i < k; i++)
//             a[l + i] = b[i];
//     }
// };
// @lc code=end