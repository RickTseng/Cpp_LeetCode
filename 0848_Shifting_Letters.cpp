#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution{
    public:
    string shiftingLetters_org(string s, vector<int>& shifts) {
        int sum = 0;
        vector<int> rec;
        for(int i = 0;i<shifts.size();i++){
             sum+=shifts[i]%26;
             shifts[i] = shifts[i]%26;
             rec.push_back(s[i]);
        }
        for(int i = 0;i<s.size();i++){
            if(i==0){
                rec[i]+=sum%26;
            }
            else{
                sum-=shifts[i-1];
                rec[i]+=sum%26;
                
            }
            if(rec[i]>122){
                rec[i]-=26;
            }
            s[i] = rec[i];
        }
        return s;
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum=0;
        for(int i=s.size()-1;i>=0;i--){
            sum=(sum+shifts[i])%26;
            s[i]=(s[i]-'a'+sum)%26 +'a';
        }
        return s;
    }
};
int main(){
    Solution sol;
    vector<int> shifts = {505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513};
    string ans = sol.shiftingLetters("mkgfzkkuxownxvfvxasy",shifts);
    printf("%d",'z');
}