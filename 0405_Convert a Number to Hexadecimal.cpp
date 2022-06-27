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
    string toHex(int num) 
    {
        if(num == 0){
            return "0";
        }
        long _num = num;
        if(_num<0){
            _num = 0xffffffff - abs(num) + 1;
        }
        vector<char> hex;
        for(int i = 0;i<10;i++){
            hex.push_back('0'+i);
        }
        for(int i = 0;i<7;i++){
            hex.push_back('a' + i);
        }
        string res = "";
        while(_num>0){
            char tmp = hex[_num % 16];
            res = tmp + res;
            _num /= 16;
        }
        return res;
    }
};
int main(){
    Solution sol;
    string ans = sol.toHex(-2);
}