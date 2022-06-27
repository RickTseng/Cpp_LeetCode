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
    string reverseVowels(string s) 
    {
        int left = 0,right = s.size()-1;
        while(left<=right)
        {
            if(validVowels(s[left]) && validVowels(s[right]))
            {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
            if(!validVowels(s[left]))
            {
                left++;
            }
            if(!validVowels(s[right]))
            {
                right--;
            }
            
        }
        return s;
    }
    bool validVowels(char c){
        vector<char> tb = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };
        for(auto t:tb)
        {
            if(c==t)
            {
                return true;
            }
        }
        return false;
    }
};