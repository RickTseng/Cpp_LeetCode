#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// Runtime: 165 ms, faster than 61.18% of C++ online submissions for Smallest Number in Infinite Set.
// Memory Usage: 46.2 MB, less than 30.26% of C++ online submissions for Smallest Number in Infinite Set.

class SmallestInfiniteSet {
private:
    //set<int> vals;
    vector<int> vals;
    int _min;
public:
    SmallestInfiniteSet() {
        vals.resize(1001,1);
        _min = 1;
    }
    
    int popSmallest() 
    {
        int rt = _min;
        vals[_min] = 0;
        for(int i = _min + 1;i<1001;++i)
        {
            if(vals[i]==1)
            {
                _min = i;
                break;
            }
        }
        return rt;
    }
    
    void addBack(int num) {
        vals[num] = 1;
        if(num<_min){
            _min = num;
        }
    }
};