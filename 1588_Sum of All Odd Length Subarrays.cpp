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
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        for(int i = 1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        int sum = arr[arr.size()-1];
        for(int b = 3;b<=arr.size();b+=2){
            for(int i = b - 1;i<arr.size();i++){
                if(i - b<0){
                    sum+= arr[i];
                }
                else{
                    sum+= arr[i]- arr[i-b];
                }
            }
        }
        return sum;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1,4,2,5,3};
    int ans = sol.sumOddLengthSubarrays(arr);
}