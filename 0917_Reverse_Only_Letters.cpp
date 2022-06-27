#include<vector>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
    public:
    string reverseOnlyLetters(string s) {
        int olen = s.size();
        int left = 0;
        int right = s.size()-1;
        while (s.size()<olen*2)
        {
            //char c = s[left];
            if (s[left]>122 || s[left]<65)
            {
                s+=s[left];
            }
            else if(s[left]>90 && s[left]<97){
                s+=s[left];
            }
            else{
                //char r = s[right];
                while ((s[right]>122 || s[right]<65)||(s[right]>90 && s[right]<97))
                {
                    right--;
                    //r = s[right];
                }
                s+=s[right];
                right--;
            }
            left++;
        }
        for(int i = 0;i<olen;i++){
            s.erase(s.begin());
        }
        return s;
    }
};
int main(){
    Solution sol;                      //Qedo1ct-eeLg=ntse-T! "Test1ng-Leet=code-Q!"
    string ans = sol.reverseOnlyLetters("-S2,_");
    printf("");
}
//[33, 122]