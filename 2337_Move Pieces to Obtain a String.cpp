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

// Ref votrubac

// We use two pointers to find the next non-blank space.

// Then, the character in the current position can be moved to the target position if:

// s[i] == t[j].
// i >= j for 'L' characters.
// i <= j for 'R' characters.

// Runtime: 56 ms, faster than 98.95% of C++ online submissions for Move Pieces to Obtain a String.
// Memory Usage: 19.1 MB, less than 67.56% of C++ online submissions for Move Pieces to Obtain a String.

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0, n = start.size();
        for (; i < n || j < n; ++i, ++j) 
        {
            while (i < n && start[i] == '_')
                ++i;
            while (j < n && target[j] == '_')
                ++j;
            if (i == n || j == n || start[i] != target[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                break;
        }
        return i == n && j == n;
    }
};