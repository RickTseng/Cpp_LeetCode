#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> tb;
        for(auto tp:candyType){
            tb.insert(tp);
        }
        return min(tb.size(),candyType.size() / 2);
    }
};