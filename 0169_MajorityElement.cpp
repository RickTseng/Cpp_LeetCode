#include<vector>
#include<stdio.h>
#include<map>
using namespace std;
class Solution{
    public:
        int majorityElement(vector<int>& nums) {
            if(nums.size()==1){
                return nums[0];
            }
            map<int,int> _map;
            int _max = 0;
            int _maxValue = 0;
            for(int i =0;i<nums.size();i++){
                if(_map.find(nums[i])==_map.end()){
                    _map[nums[i]] = 1;
                }
                else{
                    _map[nums[i]] += 1;
                    if(_map[nums[i]]>_max){
                        _max = _map[nums[i]];
                        _maxValue = nums[i];
                    }
                    
                }
                
            }
            return _maxValue;

        }
};



int main(){
    Solution solution;
    vector<int> nums(INT16_MAX,1);
    
    int x = solution.majorityElement(nums);
}