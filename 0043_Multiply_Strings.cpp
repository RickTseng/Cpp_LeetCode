#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        vector<int> res(num1.size()+num2.size(),0);
        int indexOut=0;
        for(int n2 = num2.size()-1;n2>=0;n2--){
            int index = indexOut;
            int v = 0;
            for(int n1 = num1.size()-1;n1>=0;n1--){
                int int1 = num1[n1]-'0';
                int int2 = num2[n2]-'0';
                v = (int1 * int2) / 10;
                res[index] += (int1 * int2) % 10;
                if(res[index]>9){
                    res[index+1] += res[index]/10;
                    res[index] = res[index]%10;
                    
                }
                if(v!=0){
                    res[index+1] += v;
                    if(res[index+1]>9){
                        res[index+2] += res[index+1]/10;
                        res[index+1] = res[index+1]%10;
                        
                    }
                }
                index++;
            }
            indexOut++;
        }
        string ans = "";
        if(res[res.size()-1]==0){
            res.pop_back();
        }
        for(int i = res.size()-1;i>=0;i--){
            ans+='0'+res[i];
            
        }
        return ans;
    }
};
int main(){
    Solution sol;
    string n1 = "";
    for(int i =0;i<2;i++){
        n1+='9';
    }
    string ans = sol.multiply("2","3");
}
//Runtime: 8 ms, faster than 58.53% of C++ online submissions for Multiply Strings.
//Memory Usage: 6.8 MB, less than 60.69% of C++ online submissions for Multiply Strings.