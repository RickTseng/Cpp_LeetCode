#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<bool> db(nums.size() + 1, false);
        for (auto n : nums)
        {
            if (!db[n])
            {
                db[n] = true;
            }
            else
            {
                return n;
            }
        }
        return 0;
    }
    vector<int> findErrorNums(vector<int> &nums)
    {
        /*
        Runtime: 100 ms, faster than 10.77% of C++ online submissions for Set Mismatch.
        Memory Usage: 33 MB, less than 5.21% of C++ online submissions for Set Mismatch.
        */
        map<int,int> db;
        vector<int> res;
        //sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(db.find(nums[i])==db.end()){
                db[nums[i]]=1;
            }
            else{
                res.push_back(nums[i]);
            }
            
        }
        for(int i = 1;i<=nums.size();i++){
            if(db.find(i)==db.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3,2,3,4,6,5};
    vector<int> ans = sol.findErrorNums(nums);
}
/*
Runtime: 100 ms, faster than 79.37% of C++ online submissions for Find the Duplicate Number.
Memory Usage: 61.4 MB, less than 26.52% of C++ online submissions for Find the Duplicate Number.

*/