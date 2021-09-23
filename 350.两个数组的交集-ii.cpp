/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    204.7K
 * Total Submissions: 375.8K
 * Testcase     res.emplace_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end
