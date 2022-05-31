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
    string removeDigit(string number, char digit) 
    {
        string _maxStr = "";
        for(int i = 0;i<number.size();i++)
        {
            if(number[i] == digit){
                
                number.erase(number.begin() + i);
                if(_maxStr == "")
                {
                    _maxStr = number;
                }
                else
                {
                    for(int idx = 0;idx<_maxStr.size();idx++)
                    {
                        if(number[idx]-'0' > _maxStr[idx]-'0')
                        {
                            _maxStr = number;
                            break;
                        }
                        if(number[idx]-'0' < _maxStr[idx]-'0')
                        {
                            break;
                        }
                        
                    }
                }
                number.insert(number.begin() + i,digit);
            }
        }
        return _maxStr;
    }
};
int main(){
    Solution sol;
    string ans = sol.removeDigit("133235",'3');
}