#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
/**
 * @brief Constraints:
 *
 *  1 <= queries.length <= 5 * 10^4
 *  1 <= queries[i] <= 10^9
 *  1 <= intLength <= 15
 *
 */
class Solution
{
public:
    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        vector<long long> res;
        long long start = 1, end = 10; //ex:1~9 one-digital range of palindrome.

        // calculate range of smallest palindrome to largest palindrome.
        for (int i = 3; i <= intLength; i++)
        {
            if (i % 2 == 1)
            {
                start *= 10;
                end *= 10;
            }
        }
        int count = 0;
        int idx = 0;
        while (idx < queries.size())
        {
            if(start+ queries[idx] - 1 >=end){
                //if the queries number exceed the range input (-1).
                res.push_back(-1);
            }
            else
            {
                // go to subsequent function buildPalindrome(Palindrome length, Palindrome start number + queries[]idx] - 1).
                res.push_back(buildPalindrome(intLength,start + queries[idx] - 1));
            }
            
            idx++;
        }

        return res;
    }
    long long buildPalindrome(int intLength, long long target)
    {
        int len = 1;
        for(int i = 3;i<=intLength;i++){
            // calculate Palindrome basic length
            // ex 1==2, 3==4, 5==6 ...etc
            if(i%2==1){
                len++;
            }
        }
        vector<int> db(len, 0); // use vector to record first half Palindrome number
        int idx = len - 1;
        while (target > 0)
        {
            // fill first half Palindrome number
            long long tmp = target % 10;
            db[idx] = tmp;
            target /= 10;
            idx--;
        }
        if (intLength % 2 == 1)
        {
            // ex: if intLength = 3 and db = {1,3} transfer to {1,3,1}
            idx = len - 2;
        }
        if (intLength % 2 == 0)
        {
            // ex: if intLength = 4 and db = {1,3} transfer to {1,3,3,1}
            idx = len - 1;
        }
        while (idx >= 0)
        {
            //build second half Palindrome number
            db.push_back(db[idx]);
            idx--;
        }
        long long res = 0;
        long long pow = 1;
        idx = db.size() - 1;
        while (idx >= 0)
        {
            // calculate db to Palindrome
            res+=(db[idx] * pow);
            pow*=10;
            idx--;
        }
        return res;
    }

    bool IsPalindrome(long long x)
    {
        if (x < 0)
            return false;
        long long orginal = x;
        long long result = 0;
        while (x != 0)
        {
            long long pop = x % 10;
            x /= 10;
            if (result > LLONG_MAX || (result == LLONG_MAX / 10 && pop > 7))
                return false;
            if (result < LLONG_MIN || (result == LLONG_MIN / 10 && pop < -8))
                return false;

            result = result * 10 + pop;
        }

        return orginal == result;
    }
};
int main()
{
    Solution sol;
    vector<int> queries = {2,4,6};
    vector<long long> ans = sol.kthPalindrome(queries, 4);
    auto res = sol.buildPalindrome(4, 1012);
    // system("pasue");
}