#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool digitCount(string num) {
        vector<int> tb(10,0);
        for(auto n:num){
            tb[n-'0']++;
        }
        for(int i = 0;i<num.size();i++){
            if(num[i]-'0'!=tb[i]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution sol;
    bool ans = sol.digitCount("1210");
}