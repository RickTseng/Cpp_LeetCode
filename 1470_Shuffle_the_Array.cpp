#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution{
    public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size(),0);
        for(int i =0;i<nums.size();i++){
            if(i<nums.size()/2){
                res[i*2] = nums[i];       //even index
            }
            else{
                res[2*(i-n)+1] = nums[i]; //odd index
            }
        }
        return res;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int _max = 0;
        for(auto i : candies){
            _max = max(i,_max);
        }
        for(int i =0;i<candies.size();i++){
            if(candies[i]+extraCandies>=_max){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto i:nums){
            if(i>9 && i<100){
                count++;
            }
            if(i>999 && i<10000){
                count++;
            }
            if(i>99999 && i<1000000){
                count++;
            }
        }
        return count;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> sq;
        vector<int> res;
        for(auto i:arr1){
            if(sq.find(i)==sq.end()){
                sq[i] = 1;
            }
            else{
                sq[i]++;
            }
        }
        for(int i =0;i<arr2.size();i++){
            for(int j = 0;j<sq[arr2[i]];j++){
                res.push_back(arr2[i]);
            }
            sq.erase(arr2[i]);
        }
        for(auto i:sq){
            for(int j = 0;j<i.second;j++){
                res.push_back(i.first);
            }
        }
        return res;
    }
    string tictactoe(vector<vector<int>>& moves) {
        if(moves.size()<5){
            return "Pending";
        }
        vector<vector<string>> res;
        for(int i =0;i<3;i++){
            vector<string> tmpR;
            for(int j =0;j<3;j++){
                tmpR.push_back("");
            }
            res.push_back(tmpR);
        }
        for(int i = 0;i<moves.size();i++){
            if(i%2==0){
                res[moves[i][0]][moves[i][1]] = "A";
            }
            else{
                res[moves[i][0]][moves[i][1]] = "B";
            }
        }
        for(int i = 0;i<3;i++){
            if(res[i][0]==res[i][1]&&res[i][1]==res[i][2] && res[i][0]!=""){
                return res[i][0];
            }
            if(res[0][i]==res[1][i]&&res[1][i]==res[2][i]&& res[0][i]!=""){
                return res[0][i];
            }
            if(res[0][0]==res[1][1]&&res[1][1]==res[2][2]&& res[0][0]!=""){
                return res[0][0];
            }
            if(res[0][2]==res[1][1]&&res[1][1]==res[2][0]&& res[2][0]!=""){
                return res[0][2];
            }
        }
        if(moves.size()==9){
            return "Draw";
        }
        return "Pending";
    }
};
int main(){
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19}; // ans 2,2,2,1,4,3,3,9,6,7,19
    vector<int> arr2 = {2,1,4,3,9,6};

    vector<vector<int>> moves = {
        //{0,0},{2,0},{1,1},{2,1},{2,2}
        //{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}
        
        //{1,0},{2,2},{2,0},{0,1},{1,1}
        {0,2},{2,0},{2,1},{0,1},{1,2}
    };

    Solution sol;
    string a = sol.tictactoe(moves);
    vector<int> ans = sol.relativeSortArray(arr1,arr2);
    printf("finished");
}
//Accept 8ms
