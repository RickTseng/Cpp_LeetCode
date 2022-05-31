#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class ATM {
public:
    ATM() {
        coins.resize(5,0);
        sum = 0;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0;i<banknotesCount.size();i++){
            coins[i]+=banknotesCount[i];
            sum+= coin[i] * banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        if(amount>sum){
            return {-1};
        }
        vector<int> coins_tmp = coins;
        vector<int> res(5,0);
        int idx = 4;
        while (amount > 0 && idx >= 0)
        {
            
            while (coins_tmp[idx]> 0 && coin[idx] <= amount)
            {
                long long pics = -1;
                if(amount / coin[idx] < coins_tmp[idx])
                {
                    pics = amount / coin[idx];
                }
                else
                {
                    pics = coins_tmp[idx];
                }
                amount -= pics * coin[idx];
                coins_tmp[idx]-= pics;
                res[idx]+=pics;
            }
            idx--;
            
        }
        if(amount == 0)
        {
            coins = coins_tmp;
            return res;
        }
        return {-1};  
    }
private:
    vector<int> coins;
    vector<int> coin = {20,50,100,200,500};
    long long sum;
};
int main()
{
    /**
     * @brief ["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
              [[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]
     * 
     */
    ATM atm;
    atm.deposit({0,0,1,2,10});
    atm.withdraw(4000);
    atm.deposit({0,1,0,1,1});
    atm.withdraw(600);
    atm.withdraw(550);
}