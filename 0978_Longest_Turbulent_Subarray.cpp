#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int _max = 0;
        int count = 1;
        char tmp = ' ';
        char next = ' ';
        //string tur = "";
        string cou = "1";
        if(arr.size()==1){
            return 1;
        }
        if(arr.size()==2 && arr[0]!= arr[1]){
            return 2;
        }
        for(int i = 1;i<arr.size();i++){
            if(arr[i-1]==arr[i]){
                count = 1;
            }
            else{
                if(arr[i-1]>arr[i]){
                    next = 'L';
                }
                else{
                    next = 'H';
                }
                if(next!=tmp){
                    count++;
                }
                else{
                    count = 2;
                }
            }
            tmp = next;
            cou+=("%d",count);
            _max = max(count,_max);
        }
        return _max;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {9,4,2,10,7,8,8,1,9};
    int ans = sol.maxTurbulenceSize(arr);
    printf("Ans:%d\n",ans);
}
//9,4,2,10,7,8,8,1,9
//37,199,60,296,257,248,115,31,273,176
/*
89 / 89 test cases passed.
Status: Accepted
Runtime: 118 ms
Memory Usage: 40.4 MB
*/