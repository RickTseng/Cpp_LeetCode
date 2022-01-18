#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] == target)
            {
                return left;
            }
            if (nums[right] == target)
            {
                return right;
            }
            left++;
            right--;
        }
        return -1;
    }
    int searchInsert(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1;
        int mid = (beg + end) / 2;
        if (target > nums[end])
        {
            return end + 1;
        }
        if (target < nums[0])
        {
            return 0;
        }
        while (beg <= end)
        {

            mid = (beg + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                beg += 1;
            }
            if (nums[mid] > target)
            {
                end -= 1;
            }
        }
        return mid;
    }
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> cmp;
        unordered_map<string, bool> smp;
        int c = 0;
        int count = 0;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || i ==s.size()-1)
            {
                if(i ==s.size()-1){
                    tmp+=s[i];
                }
                if (cmp.find(pattern[c]) == cmp.end())
                {
                    if(smp[tmp]){
                        return false;
                    }
                    cmp[pattern[c]] = tmp;
                    smp[tmp] = true;
                }
                else{
                    if(cmp[pattern[c]]!=tmp){
                        return false;
                    }
                }
                tmp = "";
                count++;
                c++;
            }
            else{
                tmp += s[i];
            }
            
        }
        if(count<pattern.size()){
            return false;
        }
        return true;
    }
};
int main(){
    Solution sol;
    bool ans = sol.wordPattern("abba","dog dog dog dog");
}