#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int hIndex(vector<int>& citations) {
        int count = 0;
        sort(citations.begin(),citations.end());
        reverse(citations.begin(),citations.end());
        for(int i =0;i<citations.size();i++){
            if(citations[i]>i){
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
    vector<int> citations = {1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int ans = sol.hIndex(citations);
}
//V1.0.0 210908
//Runtime: 4 ms, faster than 54.36% of C++ online submissions for H-Index.
//Memory Usage: 8.6 MB, less than 78.66% of C++ online submissions for H-Index.