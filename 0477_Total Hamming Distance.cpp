#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<unsigned long> table(32,1);
        vector<bool> zb(32,false);
        for(int i = 1;i<32;i++){
            table[i] = table[i-1] * 2;
        }
        unsigned long z = x^y;
        int idx = 31;
        int count = 0;
        while (z>0)
        {
            while (table[idx]>z)
            {
                idx--;
            }
            z-=table[idx];
            count++;
            zb[idx] = true;
        }
        return count;

        
    }
    int totalHammingDistance(vector<int>& nums) {
        vector<unsigned long> table(32, 1);
        for (int i = 1; i < 32; i++)
        {
            table[i] = table[i - 1] * 2;
        }
        vector<int> DB(32, 0);
        int _maxSize = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = 31;
            while (nums[i] > 0)
            {
                while (table[idx] > nums[i])
                {
                    idx--;
                }
                _maxSize = max(_maxSize,idx);
                nums[i] -= table[idx];
                DB[idx]++;
            }
        }
        int total = 0;
        for(auto d:DB){
            total+=(d*(nums.size()-d));
        }
        return total;
    }
    int Cnk(int n, int k)
    {
        unsigned long long nJ = 1, kJ = 1, nkJ = 1;
        for (int i = 1; i <= n; i++)
        {
            nJ *= i;
        }
        for (int i = 1; i <= k; i++)
        {
            kJ = kJ * i;
        }
        for (int i = 1; i <= n - k; i++)
        {
            nkJ *= i;
        }
        int ans = nJ / (kJ * nkJ);
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,4,8,10,16,999,10000};
    int ans = sol.totalHammingDistance(nums);
}
/*
Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^9
The answer for the given input will fit in a 32-bit integer.

Runtime: 84 ms, faster than 15.33% of C++ online submissions for Total Hamming Distance.
Memory Usage: 19.2 MB, less than 8.42% of C++ online submissions for Total Hamming Distance.
*/