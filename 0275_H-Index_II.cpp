#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int hIndex(vector<int>& citations) {
        int count = 0;
        int n = citations.size();
        for(int i =n-1;i>=0;i--){
            if(citations[i]>n-1-i){
                count++;
            }
            else{
                return count;
            }
        }
        return count;
    }
};
int main(){
    vector<int> citations = {0,1,3,5,6};
    Solution sol;
    int ans = sol.hIndex(citations);
}
//Runtime: 46 ms, faster than 5.06% of C++ online submissions for H-Index II.
//Memory Usage: 18.6 MB, less than 49.45% of C++ online submissions for H-Index II.