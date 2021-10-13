#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int divide_Org(int dividend, int divisor) {
        if(dividend == 0){
            return 0;
        }
        if(divisor == 1){
            return dividend;
        }
        int count = 0;
        if(dividend<0&&divisor>0){
            while (dividend+divisor<=0)
            {
                dividend+=divisor;
                count--;
            }
        }
        else if(dividend>0&&divisor<0){
            while (dividend+divisor>=0)
            {
                dividend+=divisor;
                count--;
            }
        }
        else if(dividend<0&&divisor<0){
            while (dividend-divisor<=0)
            {
                dividend-=divisor;
                if(count==INT32_MAX){
                    count = INT32_MAX;
                }
                else{
                    count++;
                }
                
            }
        }
        else{
            while (dividend-divisor>=0)
            {
                dividend-=divisor;
                if(count==INT32_MAX){
                    count = INT32_MAX;
                }
                else{
                    count++;
                }
            }
        }
        return count;
        
    }
    int divide(int dividend, int divisor) {
        if((dividend==INT_MIN && divisor==-1)||(dividend==INT_MAX && divisor==1)) return INT_MAX;
        if(dividend==0) return 0;
        int sign=((dividend<0)^(divisor<0))? -1 : 1;//正負=負,負正=負,負負=正,正正=正 用於結果正負號
        long long x=(long long)dividend,y=(long long)divisor;
        if(dividend<0)//都改成正數
            x=-(long long)dividend;
        if(divisor<0)
            y=-(long long)divisor;
        long long result=0;
        while(x>=y)//代表x里面还能分出y
        {
            long long temp=y,res=1;
            while(x>=(temp<<1))//然后开始比较是否大于y的倍数，一次从x里面减去最大的2^n*y
            {
                res<<=1;
                temp<<=1;
            }
            result+=res;//res代表temp里面有多少个y，所以在x减去temp后，res也要加在result里。
            x-=temp;
        }
        return sign>0 ? result : -result;
    }

};
/*-2^31 <= dividend, divisor <= 2^31 - 1*/

int main(){
    Solution sol;
    int ans = sol.divide(-2147483647,-2);
    printf("00");
}