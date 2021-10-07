#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;      
        map<char,string> ab = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };
        if(digits.size()!=0){
            for(auto c:ab[digits[0]]){
                string tmp;
                tmp+=c;
                res.push_back(tmp);
            }
            for(int i = 1;i<digits.size();i++){
                vector<string> tmp = res;
                for(int sl = 1;sl<ab[digits[i]].size();sl++){
                    res.insert(res.end(),tmp.begin(),tmp.end());
                }
                sort(res.begin(),res.end());
                for(int resIndex = 0;resIndex<res.size();resIndex++){
                    res[resIndex]+=ab[digits[i]][resIndex % ab[digits[i]].size()];
                }
            }
            return res;
        }
        else{
            return res;
        }
    }
};
int main(){
    Solution sol;
    vector<string> ans = sol.letterCombinations("2737");
}
/*****************************************************
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

2 abc
3 def
4 ghi
5 jkl
6 mno
7 pqrs
8 tuv
9 wxyz

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.7 MB, less than 39.34% of C++ online submissions for Letter Combinations of a Phone Number.


*/