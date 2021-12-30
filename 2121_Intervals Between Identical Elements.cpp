#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        vector<long long> res(arr.size(),0);
        vector<int> fq(arr.size(), 0);
        unordered_map<int, vector<pair<int,long long>>> mp;
        for (int i = 0; i < arr.size(); i++)
        {

            if (mp[arr[i]].size() > 0)
            {
                mp[arr[i]].emplace_back(i,mp[arr[i]].back().second+ i);
                fq[i] = mp[arr[i]].size() - 1;
                continue;
            }
            mp[arr[i]].emplace_back(i,i);
            fq[i] = mp[arr[i]].size() - 1;
        }
        for(auto m:mp){
            long long total = m.second.back().second;
            int base = -1;
            int _right = m.second.size()-1;
            int _left = 0;
            long long sum = 0;
            for(int i = 0;i<m.second.size();i++){
                base = m.second[i].first;
                sum = total - m.second[i].second - (_right * base) + (_left * base);
                if(_left>0){
                    sum -=  m.second[_left-1].second;
                }
                res[base] = sum;
                _left++;
                _right--;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> arr = {2, 1, 3, 1, 2, 3, 3};
    Solution sol;
    vector<long long> ans = sol.getDistances(arr);
    
}
/*
Runtime: 667 ms, faster than 29.57% of C++ online submissions for Intervals Between Identical Elements.
Memory Usage: 151.2 MB, less than 35.16% of C++ online submissions for Intervals Between Identical Elements.
Constraints:

n == arr.length
1 <= n <= 10^5
1 <= arr[i] <= 10^5

*/