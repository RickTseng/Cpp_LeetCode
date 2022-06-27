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
class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        int count = -1;
        for(int i = 0;i*10<num;i++){
            int a = i*10 + k;
            for(int j = i+1;j*10<num;j++){
                int b = j*10+k;
                if(a+b == num){
                    count++;
                }
            }
        }
        return ;
        
    }
};

// Constraints:

// 0 <= num <= 3000
// 0 <= k <= 9

int main(){
    Solution sol;
    int ans = sol.minimumNumbers(58,9);
}