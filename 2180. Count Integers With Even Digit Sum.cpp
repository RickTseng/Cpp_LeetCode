#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
public:
    int countEven(int num) {
        int count = 0;
        while (num>0)
        {
            int target = num;
            int sum = 0;
            int th = target / 1000;
            target %= 1000;
            int hu = target / 100;
            target %= 100;
            int te = num / 10;
            target %= 10;
            int ge = target;
            if((th+hu+te+ge)%2==0){
                count++;
            }
            num--;
        }
        return count;
        
        
        
    }
    bool isPowerOfTwo(int n) {
        if(n>1 && n %2==1){
            return false;
        }
        int p = 1;
        while(p<=n){
            if(p==n){
                return true;
            }
            p*=2;
        }
        return false;
    }
    uint32_t reverseBits(uint32_t n) {
        vector<int> rBit(32,0);
        int idx = 31;
        uint32_t target = 0b10000000000000000000000000000000;
        while (idx>=0)
        {
            if(n>=target){
                rBit[idx]++;
                n-=target;
            }
            idx--;
            target/=2;
        }
        uint32_t res = 0;
        target = 0b1000000000000000000000000000000;
        for(int i = 0;i<rBit.size();i++){
            if(rBit[i]==1){
                res+=target;
            }
            target/=2;
        }
        return res;
    }
    int singleNumber(vector<int>& nums) {
        //vector<int> neg(30000,0),pos(30000,0);
        map<int,int> rec;
        for(auto n:nums){
            rec[n]++;
            if(rec[n]==2){
                rec.erase(n);
            }
        }
        //auto iter = rec.begin();
        return rec.begin()->first;
    }
    
};
int main(){
    Solution sol;
    
    uint32_t ans = sol.reverseBits(43261596);
}