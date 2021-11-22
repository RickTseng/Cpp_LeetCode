#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution_org
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<bool> db(INT32_MAX, false);
        priority_queue<int> box;
        int count = 1;
        //box.push(1);
        db[1] = true;
        for (auto p : primes)
        {
            db[p] = true;
            box.push(p);
        }
        int i = 2;
        for (; i < INT32_MAX && count < n; i++)
        {
            int target = i;
            if (db[target])
            {              
                count++;
                continue;
            }

            for (auto p : primes)
            {
                if (p <= target && target % p == 0 && db[target / p])
                {
                    db[target] = true;
                    //box.push(target);
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
class Solution
{       // ref user: tensor-flower
public:
    int nthSuperUglyNumber_web(int n, vector<int> &primes)
    {
        vector<int> nums(n);
        vector<int> indices(primes.size()); // index of the prime number inside nums array
        nums[0] = 1;
        // first item is value of ugly number, second item is identity of the prime
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < primes.size(); ++i)
            pq.emplace(primes[i], i);
        for (int i = 1; i < n;)
        {
            auto [val, id] = pq.top();
            pq.pop();
            if (val != nums[i - 1])
                nums[i++] = val;                              // avoid duplicate
            if (INT_MAX / primes[id] > nums[indices[id] + 1]) // prevent overflow
                pq.emplace(nums[++indices[id]] * primes[id], id);
        }
        return nums.back();
    }
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<int> nums(n);
        vector<int> indices(primes.size()); // index of the prime number inside nums array
        nums[0] = 1;
        // first item is value of ugly number, second item is identity of the prime
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < primes.size(); ++i)
            pq.emplace(primes[i], i);
        for (int i = 1; i < n;)
        {
            auto [val, id] = pq.top();
            pq.pop();
            if (val != nums[i - 1])
                nums[i++] = val;                              // avoid duplicate
             // prevent overflow
            pq.emplace(nums[++indices[id]] * primes[id], id);
        }
        return nums.back();
    }
};
int main()
{
    Solution sol;
    vector<int> primes{2, 7, 13, 19};
    int ans = sol.nthSuperUglyNumber(1000, primes);
    int x = 0;
}
/*
Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].


Constraints:

1 <= n <= 10^6
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.

*/