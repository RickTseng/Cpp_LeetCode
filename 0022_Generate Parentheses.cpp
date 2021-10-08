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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        res.push_back("()");
        for(int i =2;i<=n;i++){
            vector<string> tmpInSide = res;
            string watch = "";
            //outside
            for(int ir = 0;ir<res.size();ir++){
                res[ir].insert(res[ir].begin(),'(');
                res[ir].insert(res[ir].end(),')');
            }
            for(int ir = 0;ir<tmpInSide.size();ir++){
                for(int s = 0;s<tmpInSide[ir].size()-1;s++){
                    vector<char> samp = {'(',')'};
                    string tmpInsert = tmpInSide[ir];
                    tmpInsert.insert(tmpInsert.begin()+s,')');
                    tmpInsert.insert(tmpInsert.begin()+s,'(');
                    if(find(res.begin(),res.end(),tmpInsert)==res.end()){
                        res.push_back(tmpInsert);
                    }
                }
            }
        }
        return res;
    }
};
int main(){
    //1 <= n <= 8
    Solution sol;
    vector<string> ans = sol.generateParenthesis(5);
}
/*
["(((())))","((()()))",
"((())())","((()))()",
"(()(()))","(()()())",
"(()())()","(())(())",
"(())()()","()((()))",
"()(()())","()(())()",
"()()(())","()()()()"]

Runtime: 80 ms, faster than 5.17% of C++ online submissions for Generate Parentheses.
Memory Usage: 7.6 MB, less than 94.79% of C++ online submissions for Generate Parentheses.
*/