#include<vector>
#include<stdio.h>
using namespace std;
int jump(vector<int>& nums){
    int len = nums.size()-1;
    int index = nums.size()-2;
    int _min = nums.size();
    vector<int> tmp;
    while (len>0)
    {
        while (index>=0)
        {
            if(nums[index]!=0){
                int _max = index+nums[index];
                if(index+nums[index]>=len){
                    _min = min(_min,index);
                }
            
            }
        
            index-=1;
        }
        tmp.push_back(_min);
        index = _min-1;
        len = _min;
    }return tmp.size();
}

int main(){
    vector<int> nums = {3,1,2,1,2,1,4,1,5,2,3,1,7,8,1,0,5,5,6,7,8,4,10,5};
    int x = jump(nums);
    printf("%d",x);
}
/*
Runtime: 202 ms, faster than 36.75% of C++ online submissions for Jump Game II.
Memory Usage: 16.4 MB, less than 42.63% of C++ online submissions for Jump Game II.
*/