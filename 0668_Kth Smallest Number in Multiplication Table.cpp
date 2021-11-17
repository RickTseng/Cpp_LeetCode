#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    // ref Howieeee master
    int find_less(int m, int n, int mid){
        int count = 0;
        for(int i=1;i<=m;i++){          // i=1,i*1 i*2 i*3
            count+= min(n,mid/i);       // i=2,i*1 i*2 i*3 找比mid小的  -> 1,2,3 <= mid/i 
        }                               //如果 mid/i 大於所有就是n個 ,不然就是 mid/i個
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1 , right = m*n;
        
        //cout << mid << endl;
        int count  = 0;
        int mid = left + (right-left)/2 ;
        while(left < right){
            mid = left + (right-left)/2;
            count = find_less(m,n,mid);
            if(count < k) //還沒找到第k小
                left = mid+1;
            else
                right = mid;
        }
        
        return right;
    }
};
int main(){
    Solution sol;
    int ans = sol.findKthNumber(10,10,90);
}
/*
Constraints:

1 <= m, n <= 3 * 10^4
1 <= k <= m * n

*/