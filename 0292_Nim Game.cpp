#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};