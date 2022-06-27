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
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int i = 0;i<=719;i++){
            string strHour = "",strMin = "";
            if(ledCountH(i/60,strHour)+ledCountM(i%60,strMin)==turnedOn)
            {
                res.push_back(strHour + ":" + strMin);
            }
        }
        return res;
    }
    int ledCountM(int x,string &str){
        int res = 0;
        str+= ('0' + (x/10));
        str+= ('0' + (x%10));
        while (x>0)
        {
            res += x%2;
            x/=2;
        }
        return res;
    }
    int ledCountH(int x,string &str){
        int res = 0;
        if(x/10!=0)
        {
            str+= ('0' + (x/10));
        }        
        str+= ('0' + (x%10));
        while (x>0)
        {
            res += x%2;
            x/=2;
        }
        return res;
    }
};