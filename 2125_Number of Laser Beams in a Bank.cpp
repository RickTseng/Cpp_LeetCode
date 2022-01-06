#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        vector<int> tmp;
        for(int r = 0;r<bank.size();r++){
            int count = 0;
            for(int c = 0;c<bank[r].size();c++){
                if(bank[r][c]=='1'){
                    count++;
                }
            }
            if(count>0){
                tmp.push_back(count);
            }
        }
        if(tmp.size()>1){
            for(int i = 1;i<tmp.size();i++){
                res+=tmp[i-1] * tmp[i];
            }
            return res;
        }
        return 0;
    }
};
/*

Runtime: 215 ms, faster than 12.20% of C++ online submissions for Number of Laser Beams in a Bank.
Memory Usage: 23.3 MB, less than 43.75% of C++ online submissions for Number of Laser Beams in a Bank.

*/