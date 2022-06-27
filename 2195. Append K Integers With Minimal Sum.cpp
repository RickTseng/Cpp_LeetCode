#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> _nums;
		for (auto n : nums) {
			_nums.insert(n);
		}
		long long res = 0;
		auto j = _nums.begin();
		for (long long i = 1; i < 1e16; i++) {
			if (j != _nums.end()) {
				if (*j != i) {
					long long _k = 0;
                    if(*j-i>k){
                        _k = k;
                    }
                    else{
                        _k = *j-i;                     
                    }
					long long tmp1 = (i * _k) + ((_k * (_k - 1)) / 2);				
					res += tmp1;
					k-=_k;
					i += _k;
					j++;
					if (k == 0) {
						break;
					}					
				}
				else
				{
					j++;
				}
			}
			else
			{
				long long _k = k;
				long long tmp1 = (i * _k) + ((_k * (_k - 1)) / 2);
				res += tmp1;
				break;
			}
			
		}
		return res;
    }
};
int main(){
    vector<int> nums = {5,6};
    Solution sol;
    long long ans = sol.minimalKSum(nums,6);
}