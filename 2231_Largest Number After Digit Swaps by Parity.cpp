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
    int largestInteger(int num) {
        vector<int> db;
        while (num > 0)
        {
            db.push_back(num % 10);
            num /= 10;
        };
        reverse(db.begin(),db.end());
        int idx = 0;
        while (idx<db.size())
        {
            if(db[idx]%2==0){
                int jdx = idx + 1;
                while (jdx<db.size())
                {
                    if(db[jdx] % 2 == 0 && db[jdx]>db[idx]){
                        swap(db[idx],db[jdx]);
                        break;
                    }
                    jdx++;
                }          
            }
            if(db[idx]%2==1){
                int jdx = idx + 1;
                while (jdx<db.size())
                {
                    if(db[jdx] % 2 == 1 && db[jdx]>db[idx]){
                        swap(db[idx],db[jdx]);
                        break;
                    }
                    jdx++;
                }          
            }
            idx++;
        }
        int res = 0;
        for(int i = 0;i<db.size();i++){
            res+=db[i];
            if(i!=db.size()-1){
                res*=10;
            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    int ans = sol.largestInteger(1234);
}