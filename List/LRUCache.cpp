// 2025-03-27 08:53:04
// 146 LRU 缓存 
//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 
// LRUCache 类：
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 示例： 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
//
// 提示： 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 


#include <unordered_map>
#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
public:
    LRUCache(int capacity)
    :_capacity(capacity) {
        _map.reserve(capacity);
    }
    
    int get(int key) {
        auto it =_map.find(key);
        if(it==_map.end()){return -1;}
        auto cacheitem = *(it->second);
        _cache.erase(it->second);
        _cache.emplace_front(cacheitem);
        _map[key] = _cache.begin();
        return cacheitem.second;
    }
    
    void put(int key, int value) {
        auto it =_map.find(key);
        if(it==_map.end()){
            if(_cache.size()>=_capacity){
                auto back = _cache.back();
               _map.erase(back.first);
                _cache.pop_back();
            }
        }else{
            _cache.erase(it->second);
        }
        _cache.emplace_front(key, value);
        _map[key] = _cache.begin();
    }

private:
    int _capacity;
    //存数据是不能只能存value ，后续要淘汰时，无法对应map的内容
    list<pair<int,int>> _cache;
    std::unordered_map<int, list<pair<int,int>>::iterator> _map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


#include <cassert>
void testBasicOperations() {
    LRUCache cache(2); // Initialize cache with capacity 2

    cache.put(1, 1); // Cache: {1=1}
    cache.put(2, 2); // Cache: {1=1, 2=2}
    assert(cache.get(1) == 1); // Access key 1, should return 1. Cache: {2=2, 1=1}

    cache.put(3, 3); // Add key 3, evicts key 2. Cache: {1=1, 3=3}
    assert(cache.get(2) == -1); // Key 2 should not exist

    cache.put(4, 4); // Add key 4, evicts key 1. Cache: {3=3, 4=4}
    assert(cache.get(1) == -1); // Key 1 should not exist
    assert(cache.get(3) == 3); // Key 3 should return 3
    assert(cache.get(4) == 4); // Key 4 should return 4
}

void testOverwriteValue() {
    LRUCache cache(2); // Initialize cache with capacity 2

    cache.put(1, 1); // Cache: {1=1}
    cache.put(2, 2); // Cache: {1=1, 2=2}
    cache.put(1, 10); // Overwrite key 1. Cache: {2=2, 1=10}
    assert(cache.get(1) == 10); // Key 1 should return updated value 10
    assert(cache.get(2) == 2); // Key 2 should return 2
}

void testEvictionOrder() {
    LRUCache cache(3); // Initialize cache with capacity 3

    cache.put(1, 1); // Cache: {1=1}
    cache.put(2, 2); // Cache: {1=1, 2=2}
    cache.put(3, 3); // Cache: {1=1, 2=2, 3=3}
    cache.get(1);    // Access key 1. Cache: {2=2, 3=3, 1=1}
    cache.put(4, 4); // Add key 4, evicts key 2. Cache: {3=3, 1=1, 4=4}

    assert(cache.get(2) == -1); // Key 2 should not exist
    assert(cache.get(3) == 3); // Key 3 should return 3
    assert(cache.get(1) == 1); // Key 1 should return 1
    assert(cache.get(4) == 4); // Key 4 should return 4
}

void testEdgeCases() {
    LRUCache cache(1); // Initialize cache with capacity 1

    cache.put(1, 1); // Cache: {1=1}
    assert(cache.get(1) == 1); // Key 1 should return 1
    cache.put(2, 2); // Add key 2, evicts key 1. Cache: {2=2}
    assert(cache.get(1) == -1); // Key 1 should not exist
    assert(cache.get(2) == 2); // Key 2 should return 2
}

void testLargeCapacity() {
    LRUCache cache(1000); // Initialize cache with capacity 1000

    for (int i = 0; i < 1000; ++i) {
        cache.put(i, i * 10); // Add 1000 keys
    }

    for (int i = 0; i < 1000; ++i) {
        assert(cache.get(i) == i * 10); // All keys should return correct values
    }

    cache.put(1000, 10000); // Add one more key, evicts key 0
    assert(cache.get(0) == -1); // Key 0 should not exist
    assert(cache.get(1000) == 10000); // Key 1000 should return 10000
}

int main() {
    testBasicOperations();
    testOverwriteValue();
    testEvictionOrder();
    testEdgeCases();
    testLargeCapacity();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}