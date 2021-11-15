#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char,int> w1;
        for(auto w:word1){
            if(w1.find(w)==w1.end()){
                w1[w] = 1;
            }
            else{
                w1[w]++;
            }
        }
        for(auto w:word2){
            if(w1.find(w)==w1.end()){
                w1[w] = -1;
            }
            else{
                w1[w]--;
            }
        }
        for(auto w:w1){
            if(w.second>3 || w.second<-3){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution sol;
    bool ans = sol.checkAlmostEquivalent("abcdeef", "abaaacc");
}
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check Whether Two Strings are Almost Equivalent.
Memory Usage: 6.4 MB, less than 38.46% of C++ online submissions for Check Whether Two Strings are Almost Equivalent.

*/