#include<vector>
#include<stdlib.h>
using namespace std;
class Solution{
    public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> tmp;
        int len = matrix.size();
        for(int i =0;i<len;i++){
            for(int j = 0;j<len;j++){
                tmp.push_back(matrix[i][j]);
            }
        }
        int index = 0;
        for(int i = len-1;i>=0;i--){
            for(int j = 0;j<len;j++){
                matrix[j][i] = tmp[index];
                index++;
            }
        }
    }

};
int main(){
    Solution sol;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(matrix);
    system("pause");
}
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
//Memory Usage: 7.2 MB, less than 32.45% of C++ online submissions for Rotate Image.