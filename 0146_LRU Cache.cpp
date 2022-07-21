#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;

// Ref riksy 's solution use list and double map
// Runtime: 482 ms, faster than 91.36% of C++ online submissions for LRU Cache.
// Memory Usage: 167 MB, less than 60.43% of C++ online submissions for LRU Cache.

class LRUCache {
private:
    int capacity;
    unordered_map<int, int> cache; // the cache database
    unordered_map<int, list<int>::iterator> address; // to store the addresses of the list
    list<int> recents; // back : lru
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)){
            // 將(address[key]拼接至 rescents的 rescent.begin())
            recents.splice(recents.begin(), recents, address[key]);
            // 更新key目前的位置
            address[key] = recents.begin();
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        cache[key] = value;
        if(address.count(key))
        {
            // 若key存在 將(address[key]拼接至 rescents的 rescent.begin())
            recents.splice(recents.begin(), recents, address[key]);
        }
        else
        {
            // 若key不存在 插在前頭
            recents.push_front(key);
        }
        // 更新key目前的位置
        address[key] = recents.begin();
        
        // 如果超出容量 刪除recents的最後(因為LRU定義-不常使用刪除)
        if(cache.size() > capacity){
            int lru = recents.back();
            address.erase(lru);
            cache.erase(lru);
            recents.pop_back();
        }
    }
};