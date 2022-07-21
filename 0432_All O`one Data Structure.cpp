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

// Runtime: 176 ms, faster than 62.02% of C++ online submissions for All O`one Data Structure.
// Memory Usage: 57.7 MB, less than 22.35% of C++ online submissions for All O`one Data Structure.

class AllOne
{
private:
    map<int, unordered_map<string, int>> count;
    unordered_map<string, int> mp;
public:
    AllOne()
    {
        count[0].empty();
    }

    void inc(string key)
    {
        if (count[mp[key]].find(key) != end(count[mp[key]]))
        {
            count[mp[key]].erase(key);
            if (count[mp[key]].empty())
            {
                count.erase(mp[key]);
            }
        }
        mp[key]++;
        count[mp[key]][key] = mp[key];
    }

    void dec(string key)
    {
        if (mp[key] == 1)
        {
            count[mp[key]].erase(key);
            if (count[mp[key]].empty())
            {
                count.erase(mp[key]);
            }
            mp.erase(key);
        }
        else
        {
            count[mp[key]].erase(key);
            if (count[mp[key]].empty())
            {
                count.erase(mp[key]);
            }
            mp[key]--;
            count[mp[key]][key] = mp[key];
        }
    }

    string getMaxKey()
    {
        auto i = --count.end();
        if (i->second.empty())
        {
            return "";
        }

        auto tar = i->second.begin()->first;
        return tar;
    }

    string getMinKey()
    {
        auto i = ++count.begin();
        if (i->second.empty())
        {
            return "";
        }
        auto tar = i->second.begin()->first;
        return tar;
    }

};
int main()
{
    AllOne allOne;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("c");
    allOne.inc("c");
    allOne.inc("c");
    allOne.dec("b");
    allOne.dec("b");
    // allOne.getMaxKey(); // return "hello"
    allOne.getMinKey(); // return "hello"
    allOne.inc("leet");
    string ans1 = allOne.getMaxKey(); // return "hello"
    string ans2 = allOne.getMinKey(); // return "leet"
}
// Input
// ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
// [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
// Output
// [null, null, null, "hello", "hello", null, "hello", "leet"]

// Explanation
// AllOne allOne = new AllOne();
// allOne.inc("hello");
// allOne.inc("hello");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "hello"
// allOne.inc("leet");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "leet"