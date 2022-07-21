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

// Runtime: 94 ms, faster than 94.82% of C++ online submissions for Design HashSet.
// Memory Usage: 43.8 MB, less than 44.92% of C++ online submissions for Design HashSet.

class MyHashSet {
private:
    vector<bool> mp;
public:
    MyHashSet() {
        mp.resize(1000001,0);
    }
    
    void add(int key) {
        mp[key] = true;
    }
    
    void remove(int key) {
        mp[key] = false;
    }
    
    bool contains(int key) {
        return mp[key];
    }
};