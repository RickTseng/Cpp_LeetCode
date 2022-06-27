#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> countSmaller_v1(vector<int> &nums)
    {
        priority_queue<int> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq2;

        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            vector<pair<int, int>> tmp;
            while (!pq2.empty() && pq2.top().first > nums[i])
            {
                tmp.push_back(pq2.top());
                pq2.pop();
            }

            if (pq2.empty())
            {
                res.push_back(0);
                pq2.emplace(nums[i], 0);
            }
            else
            {
                if (pq2.top().first == nums[i])
                {
                    auto [val, count] = pq2.top();
                    res.push_back(pq2.size());
                    pq2.pop();
                    
                    pq2.emplace(nums[i], count + 1);

                }
                else
                {
                    res.push_back(pq2.size());
                    pq2.emplace(nums[i], 1);
                }
                
            }
            while (!tmp.empty())
            {
                pq2.push(tmp.back());
                tmp.pop_back();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq2;
        map<int, int> db;
        map<int, int> output;
        vector<int> res;
        int id = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            pq2.emplace(nums[i], id++);
        }
        int count = 0;
        int curtV = -100001;
        while (!pq2.empty())
        {
            auto [val, index] = pq2.top();

            if (index >= count)
            {
                if (val == curtV)
                {
                    output[index] = db[val];
                }
                else
                {
                    db[val] = count;
                    output[index] = count;
                }
                count++;
            }
            else
            {
                output[index] = index;
            }

            curtV = val;
            pq2.pop();
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res.push_back(output[i]);
        }
        return res;
    }
    vector<int> countSmaller_v3(vector<int> &nums)
    {
        vector<int> t, res(nums.size());
        int curt = -10001;
        bool correct = false;
        for(auto n:nums){
            if(n<curt){
                correct = true;
                break;
            }
            curt = n;
        }
        if(!correct){
            return res;
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
            res[i] = d;
            t.insert(t.begin() + d, nums[i]);
        }
        return res;
    }
    //二分插入
    vector<int> countSmaller_v4(vector<int> &nums)
    {
        vector<int> ans, sorted;
        int position;
        vector<int>::iterator it;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            position = binaryInsert(sorted, nums[i]);
            it = sorted.begin() + position;
            sorted.insert(it, nums[i]);
            ans.push_back(position);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int binaryInsert(vector<int> &sorted, int num)
    {
        int left = 0, right = sorted.size() - 1, mid;
        while (left <= right)
        {
            /* code */
            mid = left + ((left + right) >>1);
            if (sorted[mid] < num)
            {
                left = mid + 1;
            }
            else if(sorted[mid] >= num)
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
class Solution_2{
    vector<int> ans;
    vector<int> tmp;
    vector<int> idx;
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        ans.resize(nums.size());
        tmp.resize(nums.size());
        idx.resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            idx[i] = i;
            ans[i] = 0;
        }
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums,left,mid,right);
    }
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right)
        {
            if(nums[idx[i]]<=nums[idx[j]]){
                ans[idx[i]]+=j-(mid+1);
                tmp[k++] = idx[i++];
            }
            else{
                tmp[k++] = idx[j++];
            }
        }
        while (i<=mid)
        {
            ans[idx[i]]+=j-(mid+1);
            tmp[k++] = idx[i++];
        }
        while (j<=right)
        {
            tmp[k++] = idx[j++];
        }
        for(i=left;i<=right;++i){
            idx[i] = tmp[i];
        }
        
    }
};

int main()
{
    Solution_2 sol;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> nums1 = {7, 8, 1, 2, 5, 4, 7, 8, 9, 9, 5, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2};
    vector<int> nums2(100000, 1);
    vector<int> nums3 = {-1, -1};
    vector<int> ans = sol.countSmaller(nums);
}
/*
Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4


*/