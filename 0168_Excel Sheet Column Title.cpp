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
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber>0)
        {
            int x = columnNumber % 26;
            char tmp = ' ';
            if(x==0){
                x = 26;
                tmp = 'Z';
            }
            else{
                tmp = (x - 1) + 'A';
            }
            
            res = tmp + res;
            columnNumber -= x;
            columnNumber /= 26;
        }
        return res;
    }
};