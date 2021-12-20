#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto w:words){
            int left = 0;
            int right = w.size()-1;
            int get = true;
            while (left<right)
            {
                if(w[left]!=w[right]){
                    get = false;
                    break;
                }
                left++;
                right--;
            }
            if(get){
                return w;
            }
            
        }
        return "";
    }
};