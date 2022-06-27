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
    bool checkPerfectNumber(int num) 
    {
        int left = 2,right = num;
        int sum = 1;
        while(left<num){
            if(num % left == 0){
                sum += left;
                if(sum>num){
                    return false;
                }
            }
            left++;
        }
        if(sum<num){
            return false;
        }

        return false;
    }
};
int main(){
    Solution sol;
    int ans = sol.checkPerfectNumber(36);
}