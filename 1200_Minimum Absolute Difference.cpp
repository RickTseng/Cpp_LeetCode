#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        int diff = 1000001;
        for(int i = 1;i<arr.size();i++){
            diff = min(diff,abs(arr[i-1]-arr[i]));
        }
        for(int i = 1;i<arr.size();i++){
            if(abs(arr[i-1]-arr[i])==diff){
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
        
    }
};
int main(){

}
/*    
2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6

*/