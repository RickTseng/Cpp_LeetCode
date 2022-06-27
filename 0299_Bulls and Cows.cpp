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

// Runtime: 4 ms, faster than 76.45% of C++ online submissions for Bulls and Cows.
// Memory Usage: 8.8 MB, less than 5.01% of C++ online submissions for Bulls and Cows.


class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,vector<int>> tb;
        vector<int> local(guess.size(),0),count(10,0);
        for(int i = 0;i<10;++i){
            tb[i+'0'];
        }
        for(int i = 0;i<secret.size();++i){
            tb[secret[i]].resize(secret.size(),0);
            tb[secret[i]][i]++;
            count[secret[i]-'0']++;
        }
        int A = 0;
        int B = 0;
        for(int idx = 0;idx<guess.size();++idx){
            if(!tb[guess[idx]].empty())
            {
                if(tb[guess[idx]][idx]==1 &&count[guess[idx]-'0']>0)
                {
                    A++;
                    local[idx]++;
                    count[guess[idx]-'0']--;
                }
            }
        }
        for(int idx = 0;idx<guess.size();++idx){
            if(!local[idx] && !tb[guess[idx]].empty())
            {
                if(count[guess[idx]-'0']>0)
                {
                    B++;
                    count[guess[idx]-'0']--;
                }
            }
        }
        string strA = "",strB = "";
        while(A>0)
        {
            char tmp = A%10 +'0';
            strA = tmp + strA;
            A/=10;
        }
        while(B>0)
        {
            char tmp = B%10 +'0';
            strB = tmp + strB;
            B/=10;
        }
        if(strA==""){
            strA = "0";
        }
        if(strB==""){
            strB = "0";
        }
        return strA + 'A' + strB + 'B';
    }
};
int main(){
    Solution sol;
    string ans = sol.getHint("1806","7801");
}