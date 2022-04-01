#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Solution {
public:
    string interpret(string command) {
        string res = "";
        int idx = 0;
        while (idx<command.size())
        {
            if(command[idx]=='G'){
                res+='G';
            }
            if(command[idx]=='('){
                if(command[idx+1]==')'){
                    res+='o';
                    idx++;
                }
                else{
                    res+='a';
                    res+='l';
                    idx+=3;
                }
            }
            idx++;
        }
        return res;
    }
    string freqAlphabets(string s) {
        int idx = s.size()-1;
        string res;
        while (idx>=0)
        {
            string tmp = "";
            if(s[idx]=='#'){
                int a = (s[idx-2] - '0')*10 + (s[idx-1] - '0');
                tmp+=('a'+ a - 1);
                idx-=3;
            }
            else{
                tmp+=('a' + (s[idx] - '1'));
                idx--;
            }
            res = (tmp + res);
        }
        return res;
    }
};
int main(){
    Solution sol;
    string ans = sol.freqAlphabets("10#11#12");
}