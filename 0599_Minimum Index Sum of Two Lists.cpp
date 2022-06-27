#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,pair<int,int>>mp;
        int _min = 2002;
        for(int i = 0;i<list1.size();i++){
            mp[list1[i]].first++;
            mp[list1[i]].second+=i;
        }
        for(int i = 0;i<list2.size();i++){
            mp[list2[i]].first++;
            mp[list2[i]].second+=i;
            if(mp[list2[i]].first == 2){
                _min = min(_min,mp[list2[i]].second);
            }
        }
        
        vector<string> res;
        for(auto it = mp.begin();it!=mp.end();++it){
            if(it->second.first == 2 && it->second.second == _min){
                res.push_back(it->first);
            }
        }
        return res;
    }
};
int main(){
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    Solution sol;
    vector<string> ans =sol.findRestaurant(list1,list2);
}