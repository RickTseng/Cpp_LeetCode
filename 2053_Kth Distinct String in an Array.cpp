#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> db;
        int index = 1;
        for(auto a:arr){
            if(db.find(a)==db.end()){
                db[a]=1;
                
            }
            else{
                db[a]++;
            }
        }
        int count = 0;
        for(auto a:arr){
            if(db[a]==1){
                count++;
            }
            if(count==k){
                return a;
            }
        }
        
        return "";
    }
};
int main(){
    vector<string> arr= {"d","b","c","b","c","a"};
    Solution sol;
    string ans = sol.kthDistinct(arr,2);
    printf("End\n");
}


/*
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.

*/