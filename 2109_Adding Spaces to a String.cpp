#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string res(s.size()+spaces.size(),'-');
        int a = 0;
        for(auto i:spaces){
            res[i+a++] = ' ';
        }
        for(int i = 0,j=0;i<res.size();i++){
            if(res[i]!=' '){
                res[i] = s[j++];
            }
        }
        return res;
        
    }
};
int main(){
    string s = "";
    vector<int> spaces;
    for(int i = 0;i<300000;i++){
        spaces.push_back(i);
        s+='g';
    }
    Solution sol;
    string ans = sol.addSpaces(s,spaces);
}
/*

1 <= s.length <= 3 * 10^5
s consists only of lowercase and uppercase English letters.
1 <= spaces.length <= 3 * 10^5
0 <= spaces[i] <= s.length - 1
All the values of spaces are strictly increasing.

*/