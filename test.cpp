#include<stdio.h>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> res;
    for (int row = 0; row < obstacleGrid.size(); row++) {
        vector<int> rrr;
        for (int col = 0; col < obstacleGrid[row].size(); col++) {
            rrr.push_back(1);
            if (obstacleGrid[row][col] == 1 && row == 0 && col == 0) {
                return 0;
            }
        }
        res.push_back(rrr);
    }
    bool stock = false;
    for (int row = 0; row < obstacleGrid.size(); row++) {
        for (int col = 0; col < obstacleGrid[row].size(); col++) {
            if (row == 0) {
                if (obstacleGrid[row][col] == 1 || stock) {
                    res[row][col] = 0;
                    stock = true;
                }
            }
            else
            {
                if (col == 0) {
                    if (obstacleGrid[row][col] == 1) {
                        for (int t = row; t < obstacleGrid.size(); t++) {
                            res[t][col] = 0;
                        }
                        
                    }
                }
                else
                {
                    if (obstacleGrid[row][col] == 1) {
                        res[row][col] = 0;
                    }
                    else
                    {
                        res[row][col] = res[row - 1][col] + res[row][col - 1];
                    }
                    
                }
            }
        }
        
    }
    return res[res.size() - 1][res[0].size() - 1];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    vector<int> line(10001,0);
    int _min = 10001;
    int _max = 0;
    for(int i = 0;i<intervals.size();i++){
        for (int j = intervals[i][0];j<=intervals[i][1];j++){
            if(line[j]!=1){
                if(j==intervals[i][1]){
                    line[j] = 2;
                }
                else{
                    line[j] = 1;
                }
                _min = min(_min,intervals[i][0]);
                _max = max(_max,intervals[i][1]);
            }
                
        }
        if(intervals[i][0]== intervals[i][1]){
            if(line[intervals[i][0]]!=1){
                line[intervals[i][0]] = 2;
                _min = min(_min,intervals[i][0]);
                _max = max(_max,intervals[i][1]);
            }
            
            
        }
    }
    for(int i = 0;i<line.size();i++){
        vector<int> tmp;
        if(i>_max){
            break;
        }
        if(line[i]==1){
            tmp.push_back(i);
            for(int j = 1;j<line.size();j++){
                if(line[i+j]==2){
                    tmp.push_back(i+j);
                    i+=j;
                    res.push_back(tmp);
                    break;
                }
            }
        }
        else if(line[i]==2){
            res.push_back({i,i});
        }
    }
    return res;
}
bool canJump_org(vector<int>& nums) {
        vector<int> line(nums.size(),0);
        if(nums[0]==0){
            if(nums.size()==1){
                return true;
            }
            else{
                return false;
            }
            
        }
        line[0] = 1;
        int point = -1;
        for(int i =0;i<nums.size()-1;i++){
            if(line[line.size()-1]==1){
                return true;
            }
            if(line[i]!=0){
                int j = 1;
                for(;j<=nums[i];j++){
                    if(i+j<line.size()){
                        line[i+j] = 1;
                        point = i+j;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                return false;
            }
            
            
        }
        if(line[line.size()-1]==1){
            return true;
        }
        else{
            return false;
        }
    }
    int findMin(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int _min = nums[0];
        int i = 1;
        while (nums[i]>_min)
        {
            i+=1;
            if(i>nums.size()-1){
                i-=nums.size();
            }
        }
        return nums[i];
    }


int main(int argc,char* argv[])
{
    vector<int> nums = {4,5,6,1,2,3};
    printf("%d\n",findMin(nums));
    printf("Program Finished!\n");
    
}