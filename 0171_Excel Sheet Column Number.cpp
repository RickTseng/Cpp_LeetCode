#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int sum = 0;
        for(int i = 0;i<columnTitle.size();i++){
            sum+=(columnTitle[i]-'A'+1);
            if(i!=columnTitle.size()-1){
                sum*=26;
            }

        }
        return sum;
    }
};
/**
 * @brief Constraints:

 * 1 <= columnTitle.length <= 7
 * columnTitle consists only of uppercase English letters.
 * columnTitle is in the range ["A", "FXSHRXW"].
 * 
 */