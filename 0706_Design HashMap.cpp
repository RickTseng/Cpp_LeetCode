#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class MyHashMap
{
public:
    MyHashMap()
    {
        db.resize(1000001,-1);
    }

    void put(int key, int value)
    {
        db[key] = value;
    }

    int get(int key)
    {
        return db[key];
    }

    void remove(int key)
    {
        db[key] = -1;
    }
private:
    vector<int> db;
};