/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (54.90%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 39.7K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。
 * 
 * 实现 NumArray 类：
 * 
 * 
 * 
 * 
 * NumArray(int[] nums) 用整数数组 nums 初始化对象
 * void update(int index, int val) 将 nums[index] 的值更新为 val
 * int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] +
 * nums[left + 1], ..., nums[right]）
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * 输出：
 * [null, 9, null, 8]
 * 
 * 解释：
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // 返回 9 ，sum([1,3,5]) = 9
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // 返回 8 ，sum([1,2,5]) = 8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -100 
 * 0 
 * -100 
 * 0 
 * 最多调用 3 * 10^4 次 update 和 sumRange 方法
 * 
 * 
 * 
 * 
 */

// @lc code=start
class FenwickTree
{
private:
    vector<int> sums_;
    int lowbit(int n)
    {
        return n & -n;
    }

public:
    FenwickTree(int n) : sums_(n + 1, 0) {}
    void update(int i, int del)
    {
        while (i < sums_.size())
        {
            sums_[i] += del;
            i += lowbit(i);
        }
    }
    int query(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
};
class NumArray
{
private:
    FenwickTree _tree;
    vector<int> nums_;

public:
    NumArray(vector<int> &nums) : nums_(move(nums)), _tree(nums.size())
    {
        for (int i = 0; i < nums_.size(); i++)
        {
            _tree.update(i + 1, nums_[i]);
        }
    }

    void update(int index, int val)
    {
        _tree.update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }

    int sumRange(int left, int right)
    {
        return _tree.query(right + 1) - _tree.query(left);
    }
};
// class FenwickTree
// {
// private:
//     int lowbit(int x) { return x & (-x); }
//     vector<int> sums_;
// public:
//     FenwickTree(int n) : sums_(n + 1, 0) {}
//     void update(int i, int delta)
//     {
//         while (i < sums_.size())
//         {
//             sums_[i] += delta;
//             i += lowbit(i);
//         }
//     }
//     int query(int i)
//     {
//         int sum = 0;
//         while (i > 0)
//         {
//             sum += sums_[i];
//             i -= lowbit(i);
//         }
//         return sum;
//     }
// };
// class NumArray
// {
// private:
//     vector<int> nums_;
//     FenwickTree tree_;
// public:
//     NumArray(vector<int> &nums) : nums_(move(nums)), tree_(nums_.size())
//     {
//         for (int i = 0; i < nums_.size(); ++i)
//             tree_.update(i + 1, nums_[i]);
//     }
//     void update(int i, int val)
//     {
//         tree_.update(i + 1, val - nums_[i]);
//         nums_[i] = val;
//     }
//     int sumRange(int i, int j)
//     {
//         return tree_.query(j + 1) - tree_.query(i);
//     }
// };
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
