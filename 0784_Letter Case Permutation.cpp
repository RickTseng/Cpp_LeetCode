#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> res;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] - 'A' < 26 && s[i] - 'A' >= 0) || (s[i] - 'a' < 26 && s[i] - 'a' >= 0))
            {
                if (!res.empty())
                {
                    vector<string> restmp;
                    for (int j = 0; j < res.size(); j++)
                    {
                        string tmpABC = res[j]+tmp;
                        if (s[i] > 96)
                        {
                            restmp.push_back(tmpABC += (s[i] - 32));
                        }
                        else
                        {
                            restmp.push_back(tmpABC += s[i] + 32);
                        }
                        tmpABC = res[j]+tmp;
                        restmp.push_back(tmpABC += s[i]);
                    }
                    res = restmp;
                    
                }
                else
                {
                    string tmpABC = tmp;
                    if (s[i] > 96)
                    {
                        res.push_back(tmpABC += (s[i] - 32));
                    }
                    else
                    {
                        res.push_back(tmpABC += s[i] + 32);
                    }
                    tmpABC = tmp;
                    res.push_back(tmpABC += s[i]);
                    
                }
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }
        }
        if(res.empty()){
            res.push_back(tmp);
            return res;
        }
        if(tmp!=""){
            for(auto &r:res){
                r+=tmp;
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<string> ans = sol.letterCasePermutation("a1B2");
}
/**
 * @brief Runtime: 11 ms, faster than 35.79% of C++ online submissions for Letter Case Permutation.
 * Memory Usage: 12.3 MB, less than 13.41% of C++ online submissions for Letter Case Permutation.
 * 
 */