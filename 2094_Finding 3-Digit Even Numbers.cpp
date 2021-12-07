#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int> mp0,mp;
        for(auto d:digits){
            if(mp0.find(d)==mp0.end()){
                mp0[d]=1;
            }
            else{
                mp0[d]++;
            }
        }      
        vector<int> res;
        for(int i = 100;i<1000;i+=2){
            mp = mp0;
            int target = i;
            int b = i/100;
            if(mp.find(b)==mp.end() || mp[b]<1){
                continue;
            }
            else{
                mp[b]--;
            }
            int o = (target-=(b*100))/10;
            if(mp.find(o)==mp.end() || mp[o]<1){
                continue;
            }
            else{
                mp[o]--;
            }
            int t = (target-=(o*10));
            if(mp.find(t)==mp.end() || mp[t]<1){
                continue;
            }
            else{
                mp[t]--;
            }
            res.push_back(i);
        }
        return res;

    }
    bool jd(int i,priority_queue<int,vector<int>,greater<>> pq){
        return false;
    }
};
int main(){
    std::string str = "123";
    cout<< sizeof(str)<< endl;
    Solution sol;
    std::vector<int> digits = {1,3,5,7,9};
    /*
    for(int i = 0;i<24;i++){
        for(int j = 0;j<4;j++){
            digits.push_back(j);
        }
    }
    */
    vector<int> ans = sol.findEvenNumbers(digits);

}
/*

Constraints:

3 <= digits.length <= 100
0 <= digits[i] <= 9

Runtime: 22 ms, faster than 78.91% of C++ online submissions for Finding 3-Digit Even Numbers.
Memory Usage: 9.3 MB, less than 84.10% of C++ online submissions for Finding 3-Digit Even Numbers.


*/