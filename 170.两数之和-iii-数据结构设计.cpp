/*
 * @lc app=leetcode.cn id=170 lang=cpp
 *
 * [170] 两数之和 III - 数据结构设计
 *
 * https://leetcode-cn.com/problems/two-sum-iii-data-structure-design/description/
 *
 * algorithms
 * Easy (41.61%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 19.2K
 * Testcase Example:  '["TwoSum","add","add","add","find","find"]\n[[],[1],[3],[5],[4],[7]]'
 *
 * 设计一个接收整数流的数据结构，该数据结构支持检查是否存在两数之和等于特定值。
 * 
 * 实现 TwoSum 类：
 * 
 * 
 * TwoSum() 使用空数组初始化 TwoSum 对象
 * void add(int number) 向数据结构添加一个数 number
 * boolean find(int value) 寻找数据结构中是否存在一对整数，使得两数之和与给定的值相等。如果存在，返回 true ；否则，返回
 * false 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["TwoSum", "add", "add", "add", "find", "find"]
 * [[], [1], [3], [5], [4], [7]]
 * 输出：
 * [null, null, null, null, true, false]
 * 
 * 解释：
 * TwoSum twoSum = new TwoSum();
 * twoSum.add(1);   // [] --> [1]
 * twoSum.add(3);   // [1] --> [1,3]
 * twoSum.add(5);   // [1,3] --> [1,3,5]
 * twoSum.find(4);  // 1 + 3 = 4，返回 true
 * twoSum.find(7);  // 没有两个整数加起来等于 7 ，返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^5 
 * -2^31 
 * 最多调用 5 * 10^4 次 add 和 find
 * 
 * 
 */

// @lc code=start
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {

    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {

    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
// @lc code=end

