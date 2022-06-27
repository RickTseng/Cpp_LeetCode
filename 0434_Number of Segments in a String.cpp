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
    int countSegments(string s) {
        while (s!="" && s.back()==' ')
        {
            s.pop_back();
        }
        
        int count = 0;
        for(int i = 0;i<s.size();i++)
        {
            while (i<s.size() && s[i] == ' ')
            {
                i++;
            }
            while (i<s.size() && s[i] != ' ')
            {
                i++;
            }
            count++;
            
        }
        return count;
    }
};
int main(){
    Solution sol;
    int ans = sol.countSegments("     Hello");
}