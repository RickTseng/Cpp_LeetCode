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
            
        }
        return count;

        
    }
};
int main(){
    Solution sol;
    int ans = sol.hammingDistance(7,0);
}
/*
0 <= x, y <= 2^31 - 1

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
Memory Usage: 6 MB, less than 24.75% of C++ online submissions for Hamming Distance.
*/