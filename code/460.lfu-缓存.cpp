/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (42.80%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    19.8K
 * Total Submissions: 46K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。
 * 
 * 实现 LFUCache 类：
 * 
 * 
 * LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
 * int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
 * void put(int key, int value) -
 * 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除
 * 最久未使用 的键。
 * 
 * 
 * 注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你是否可以在 O(1) 时间复杂度内执行两项操作？
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * 输出：
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 * 
 * 解释：
 * LFUCache lFUCache = new LFUCache(2);
 * lFUCache.put(1, 1);
 * lFUCache.put(2, 2);
 * lFUCache.get(1);      // 返回 1
 * lFUCache.put(3, 3);   // 去除键 2
 * lFUCache.get(2);      // 返回 -1（未找到）
 * lFUCache.get(3);      // 返回 3
 * lFUCache.put(4, 4);   // 去除键 1
 * lFUCache.get(1);      // 返回 -1（未找到）
 * lFUCache.get(3);      // 返回 3
 * lFUCache.get(4);      // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 最多调用 10^5 次 get 和 put 方法
 * 
 * 
 */

// @lc code=start
struct Node {
    int key, val, freq;
    Node(int _key, int _val, int _freq):key(_key), val(_val), freq(_freq) {}
};
class LFUCache {
private:
    int cap;
    int minFreq;
    unordered_map<int, list<Node>::iterator> keyTable;
    unordered_map<int, list<Node>> freqTable;
    void increaseFreq(int key) {
        list<Node>::iterator node = keyTable[key];
        int freq = node->freq;
        int val = node->val;
        freqTable[freq].erase(node);
        if(freqTable[freq].size() == 0) {
            freqTable.erase(freq);
            if(freq == minFreq)
                minFreq += 1;
        }
        freqTable[freq + 1].push_front(Node(key, val, freq + 1));
        keyTable[key] = freqTable[freq + 1].begin();
    }
    void removeMinFreqKey() {
        Node nodeTodelete = freqTable[minFreq].back();
        freqTable[minFreq].pop_back();
        if(freqTable[minFreq].size() == 0)
            freqTable.erase(minFreq);
        keyTable.erase(nodeTodelete.key);
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        keyTable.clear();
        freqTable.clear();
    }
    
    int get(int key) {
        if(cap == 0)
            return -1;
        auto it = keyTable.find(key);
        if(it == keyTable.end())
            return -1;
        increaseFreq(key);
        return it->second->val;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        auto it = keyTable.find(key);
        if(it != keyTable.end()) {
            increaseFreq(key);
            keyTable[key]->val = value;
        }else {
            if(keyTable.size() == cap) {
                removeMinFreqKey();
            }
            freqTable[1].push_front(Node(key, value, 1));
            keyTable[key] = freqTable[1].begin();
            minFreq = 1;
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

