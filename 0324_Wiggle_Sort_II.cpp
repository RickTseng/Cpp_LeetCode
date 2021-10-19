#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<queue>
using namespace std;
class Solution{
    public:
        void wiggleSort(vector<int>& nums) {
            
            priority_queue<int,vector<int>,greater<int>> SF;
            priority_queue<int,vector<int>> LF;
            for(auto i:nums){
                LF.push(i);
            }
            int index = 0;
            while (!SF.empty()||!LF.empty())
            {
                nums[index+1]=LF.top();
                LF.pop();
                while (LF.top()==nums[index+1])
                {
                    SF.push(LF.top());
                    LF.pop();
                }
                nums[index] = LF.top();
                LF.pop();
                while (!LF.empty())
                {
                    SF.push(LF.top());
                    LF.pop();
                }



                nums[index+2] = SF.top();
                SF.pop();
                while (SF.top()==nums[index+2])
                {
                    LF.push(SF.top());
                    SF.pop();
                }
                nums[index+3] = SF.top();
                SF.pop();
                while (!SF.empty())
                {
                    LF.push(SF.top());
                    SF.pop();
                }
                index+=4;
            }
            
        
        }
};
int main(){
    Solution sol;
    vector<int> nums = {1,1,1,1,2,2,2,3,3,3};
    sol.wiggleSort(nums);
    printf("Pause");
}