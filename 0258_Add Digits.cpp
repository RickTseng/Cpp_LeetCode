#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    int addDigits(int num)
    {
        
        while (num > 9)
        {
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
int main(){
    Solution sol;
    int ans = sol.addDigits(38);
}