#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(auto c:coins){
            for(int i = c;i<=amount;i++){
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
        return dp[amount]>amount? -1 : dp[amount];
    }
    

};
int main(){
    Solution sol;
    vector<int> coins = {1,2,5,7,11,22,33,555,999,1111,2222,INT32_MAX};
    vector<int> coins2 = {186,419,83,408};
    int ans = sol.coinChange(coins2,6249);
}
/*
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4

[3,7,405,436]
8839

[186,419,83,408]
6249 ans:20

*/