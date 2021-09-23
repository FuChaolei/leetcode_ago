// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem146.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (52.63%)
 * Likes:    1554
 * Dislikes: 0
 * Total Accepted:    208.9K
 * Total Submissions: 397K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
 * 
 * 
 * 
 * 实现 LRUCache 类：
 * 
 * 
 * LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value)
 * 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 0 
 * 最多调用 2 * 10^5 次 get 和 put
 * 
 * 
 */

// @lc code=start
class LRUCache
{
private:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> ls;
    int c;

public:
    LRUCache(int capacity)
    {
        c = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            auto it = mp[key];
            ls.splice(ls.begin(), ls, it);
            return it->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = mp.find(key);
        if (it != mp.end())
        {
            mp[key]->second = value;
            ls.splice(ls.begin(), ls, it->second);
            return;
        }
        if (mp.size() == c)
        {
            auto it = mp.find(ls.back().first);
            mp.erase(it);
            ls.pop_back();
        }
        ls.emplace_front(key, value);
        mp[key] = ls.begin();
    }
};

// class LRUCache
// {
// public:
//     LRUCache(int capacity)
//     {
//         capacity_ = capacity;
//     }
//     int get(int key)
//     {
//         const auto it = m_.find(key);
//         // If key does not exist
//         if (it == m_.cend())
//             return -1;
//         // Move this key to the front of the cache
//         cache_.splice(cache_.begin(), cache_, it->second);
//         return it->second->second;
//     }
//     void put(int key, int value)
//     {
//         const auto it = m_.find(key);
//         // Key already exists
//         if (it != m_.cend())
//         {
//             // Update the value
//             it->second->second = value;
//             // Move this entry to the front of the cache
//             cache_.splice(cache_.begin(), cache_, it->second);
//             return;
//         }
//         // Reached the capacity, remove the oldest entry
//         if (cache_.size() == capacity_)
//         {
//             const auto &node = cache_.back();
//             m_.erase(node.first);
//             cache_.pop_back();
//         }
//         // Insert the entry to the front of the cache and update mapping.
//         cache_.emplace_front(key, value);
//         m_[key] = cache_.begin();
//     }
// private:
//     int capacity_;
//     list<pair<int, int>> cache_;
//     unordered_map<int, list<pair<int, int>>::iterator> m_;
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
