#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
/*
3Fizz5Buzz
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> res;
        for(int i = 1;i<=n;i++){
            string tmp = "";
            if(i%3==0 && i%5 == 0)
            {
                res.push_back("FizzBuzz");
                continue;
            }
            if(i%3==0)
            {
                res.push_back("Fizz");
                continue;
            }
            if(i%5==0){
                res.push_back("Buzz");
                continue;
            }
            res.push_back(build(i));
        }
        return res;
    }
    string build(int x)
    {
        string res = "";
        while (x>0)
        {
            char tmp = '0' + x % 10;
            res = tmp + res;
            x/=10;
        }
        return res;
    }
};