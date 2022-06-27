#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
// A password is said to be strong if it satisfies all the following criteria:

// It has at least 8 characters.
// It contains at least one lowercase letter.
// It contains at least one uppercase letter.
// It contains at least one digit.
// It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
// It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
// Given a string password, return true if it is a strong password. Otherwise, return false.
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8)
        {
            return false;
        }
        bool lc = false;
        bool uc = false;
        bool di = false;
        bool sp = false;
        char befc = ' ';
        vector<char> spTable = {'!','@','#','$','%','^','&','*','(',')','-','+'};
        for(int i = 0;i<password.size();i++)
        {
            if(password[i]==befc){
                return false;
            }
            befc = password[i];
            if(!lc && password[i]>='a' && password[i]< 'a' + 26)
            {
                lc = true;
            }
            if(!uc && password[i]>='A' && password[i]< 'A' + 26)
            {
                uc = true;
            }
            if(!di && password[i]>='0' && password[i]< '0' + 10)
            {
                di = true;
            }
            if(!sp)
            {
                for(auto c:spTable){
                    if(password[i]==c)
                    {
                        sp = true;
                        break;
                    }
                }
            }
        }
        return lc && uc && di && sp ? true:false;
    }
};