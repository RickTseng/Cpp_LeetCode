#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        map<string, int> db;
        for (auto word : words)
        {
            if (db.find(word) == db.end())
            {
                db[word] = 1;
            }
            else
            {
                db[word]++;
            }
        }
        int count = 0;
        bool midWord = false;
        for(auto word:db)
        {
            if(word.first[0] == word.first[1])
            {
                if(word.second>1){
                    count+= ((word.second/2) * 4);
                    db[word.first]%=2;
                }
                if(db[word.first] == 1 && !midWord){
                    midWord = true;
                    count+=2;
                }
                continue;
            }
            string rWord ="";
            rWord += word.first[1];
            rWord += word.first[0];
            if(db.find(rWord)!=db.end()){
                count += (min(word.second,db[rWord])*4);
                db[word.first] = 0;
                db[rWord] = 0;
            }
            
        }
        return count;
    }
};
int main(){
    Solution sol;
    vector<string> words = {"lc","cl","gg","gg","ab"};
    int ans = sol.longestPalindrome(words);
}
/*

Runtime: 1001 ms, faster than 16.67% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
Memory Usage: 167.8 MB, less than 25.00% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.

*/
