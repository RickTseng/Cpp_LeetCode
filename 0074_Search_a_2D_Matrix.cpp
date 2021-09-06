#include<vector>
#include<stdio.h>
using namespace std;
class Solution{
    public:
        bool searchMatrix_org(vector<vector<int>>& matrix, int target) {
            
            for(int i = 0;i<matrix.size();i++){
                if(matrix[i][matrix[i].size()-1]>target&&matrix[i][0]>target){
                    return false;
                }
                if(matrix[i][matrix[i].size()-1]>=target){
                    int s = 0;
                    int e = matrix[i].size();
                    int mid = 0;
                    while (s<=e)
                    {
                        mid = s + (e-s)/2;
                        int cur = matrix[i][mid];
                        if(matrix[i][mid]==target){
                            return true;
                        }
                        if(matrix[i][mid]>target){
                            e=mid-1;
                        }
                        if(matrix[i][mid]<target){
                            s=mid+1;
                        }
                    }
                    
                }
            }
            return false;

            
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int h = 0, w = matrix[0].size(), x;
            while(h < matrix.size() && w && (x = matrix[h][w-1]) != target) 
            {
                if (x > target){
                    w--;
                } 
                else{
                    h++;
                } 
            }
            while (matrix.size()){
                matrix.pop_back();
            } 
            return x == target;
        }

};
int main(){
    Solution sol;
    vector<vector<int>> ttmp;
    int count = 1;
    for(int i = 0;i<300;i++){
        vector<int> tmp;
        for(int j = 0;j<300;j++){
            tmp.push_back(count);
            count++;
        }
        ttmp.push_back(tmp);
    }
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    bool ans = sol.searchMatrix(ttmp,45772);
}
//Org version
//Runtime: 376 ms, faster than 8.30% of C++ online submissions for Search a 2D Matrix II.
//Memory Usage: 14.9 MB, less than 68.80% of C++ online submissions for Search a 2D Matrix II.

//Fastest
//Runtime: 32 ms, faster than 99.93% of C++ online submissions for Search a 2D Matrix II.
//Memory Usage: 14.9 MB, less than 68.80% of C++ online submissions for Search a 2D Matrix II.