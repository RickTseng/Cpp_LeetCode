#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * 
 */

class Solution {
public:
    int guess(int num){
        if (num > 6) {
            return -1;
        } 
        else if (num == 6) {
            return 0;
        }  
        else {
            return 1;
        }
}
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (guess(mid) == -1) {
                high = mid - 1;
            } else if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) == 1) {
                low = mid + 1;
            }
        }
        return -1;
    }
};
int main(){
    Solution sol;
    int ans = sol.guessNumber(10);
}