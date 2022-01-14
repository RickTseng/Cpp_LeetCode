#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> tmp;
        int i = 0;
        while (i < path.size())
        {
            if (path[i] == '/')
            {
                string pp = "";
                int j = i + 1;
                while (j < path.size() && path[j] != '/')
                {
                    pp += path[j];
                    j++;
                }
                if (pp == "..")
                {
                    if (!tmp.empty())
                        tmp.pop_back();
                }
                else if (pp == "" || pp == ".")
                {
                }
                else
                {
                    tmp.emplace_back(pp);
                }
                i = j;
            }
            else
            {
                i++;
            }
        }
        string res = "";
        if(tmp.empty()){
            return"/";
        }
        for (auto t : tmp)
        {
            res += '/' + t;
        }
        return res;
    }
};
int main()
{
    Solution sol;
    string ans = sol.simplifyPath("/../");
}
/*

Runtime: 8 ms, faster than 55.38% of C++ online submissions for Simplify Path.
Memory Usage: 9.3 MB, less than 63.05% of C++ online submissions for Simplify Path.

*/