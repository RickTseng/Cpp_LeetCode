#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
class Solution
{

public:
    vector<int> vS1, vS2;
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        vS1.resize(26, 0);
        vS2.resize(26, 0);
        for (auto c : s1)
        {
            vS1[c - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++)
        {
            vS2[s2[i] - 'a']++;
        }
        for (int i = s1.size(); i < s2.size(); i++)
        {
            if (judge())
            {
                return true;
            }
            vS2[s2[i - s1.size()] - 'a']--;
            vS2[s2[i] - 'a']++;
        }
        if (judge())
        {
            return true;
        }
        return false;
    }
    bool judge()
    {
        for (int i = 0; i < 26; i++)
        {
            if (vS1[i] != vS2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool containsDuplicate(vector<int>& nums) {
        set<int> db;
        int s = 0;
        for(auto n:nums){
            db.insert(n);
            if(db.size()==s){
                return true;
            }
            s = db.size();
        }
        return false;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        if(m==0){
            nums1 = nums2;
            return;
        }
        int i = 0,j=0;
        vector<int> tmp;
        while (i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
            {
                tmp.push_back(nums1[i]);
                i++;
                continue;
            }
            if(nums1[i]==nums2[j])
            {
                tmp.push_back(nums1[i]);
                tmp.push_back(nums2[j]);
                i++;
                j++;
                continue;
            }
            if(nums1[i]>nums2[j])
            {
                tmp.push_back(nums2[j]);
                j++;
                continue;
            }
        }
        for(;i<m;i++){
            tmp.push_back(nums1[i]);
        }
        for(;j<n;j++){
            tmp.push_back(nums2[j]);
        }
        nums1 = tmp;
        


    }
        vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};
int main()
{
    Solution sol;
    bool ans = sol.checkInclusion("adc", "dcda");
}