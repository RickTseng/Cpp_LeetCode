#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            dp[i] = i-1;
            int left = 1,right = i-1;
            while (left<=right)
            {
                dp[i] = max(dp[i],dp[left]*dp[right]);
                left++;
                right--;
            }
            
        }
        return dp[n];
    }
};
int main(){
    Solution sol;
    int ans = sol.integerBreak(10);
}
/**
 * @brief 2 <= n <= 58
 * 
 */