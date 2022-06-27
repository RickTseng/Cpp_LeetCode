#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        
        int up = 0 , lo = 0;
        for(int i = 0;i<word.size();i++)
        {
            if (word[1] > 96 && word[1] < 123)
            {
                lo++;
            }
            else
            {
                up++;
            }
        }
        if(up == word.size()){
            return true;
        }
        if(lo == word.size()){
            return true;
        }
        if((word[0] > 64 && word[0] < 91) && lo == word.size() - 1)
        {
            return true;
        }
        return false;
    }
};
int main(){
    int a = 'a';
    int z = 'z';
    cout << a << endl;
    cout << z << endl;
    Solution sol;
    bool ans = sol.detectCapitalUse("FlaG");
}