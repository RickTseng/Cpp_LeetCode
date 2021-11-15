#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> db;
        for(int r = 0;r<matrix.size();r++){
            for(int c = 0;c<matrix[r].size();c++){
                db.push_back(matrix[r][c]);
            }
        }
        sort(db.begin(),db.end());
        
        
        return db[k-1];
    }
};
int main(){
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    vector<vector<int>> matrix1 = {{1,2},{1,3}};
    Solution sol;
    int ans = sol.kthSmallest(matrix1,2);
}
/*
Input: matrix = {{1,5,9},{10,11,13},{12,13,15}}, k = 8
Output: 13
Explanation: The elements in the matrix are {1,5,9,10,11,12,13,13,15}, and the 8th smallest number is 13

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
Runtime: 32 ms, faster than 71.24% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
Memory Usage: 14.5 MB, less than 30.02% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.

*/