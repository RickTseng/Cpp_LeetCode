#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
class Solution{
public:
    int climbStairs(int n) {
        /*
        int count = 0;
        vector<int> stair = {n/2,n/1};
        for(int i =0;i<=stair[0];i++){
            if(i==0){
                count++;
            }
            else{
                count+=calculate(i+(n-2*i),i);
            }
        }
        return count;
        */
        if(n==1){
            return 1;
        }
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i =2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
    int calculate(int total,int twos){
        /******************/
        /*  n!/k!(n-k)!   */
        /******************/
        unsigned long long int nJ = 1;
        unsigned long long kJ = 1;
        unsigned long long nkJ = 1;
        long int a,i,b,d; //a是計次變數(指數的)；i是第幾位數之變數；b是計次變數(輸出的)；d是位數-1，即陣列的最大值
        long long int n,m,v,sx,sy; //n是底數；m是指數；v是進位暫存變數；s用來記錄整數位數
        //long long int x[100000]={0};
        vector<long long> x(10,0);
        vector<long long> y(10,0);
        v=0; //清空v的值
        sx=1; //不管怎麼樣，s必會大於等於1，因為整數一定有位數
        x[0]=1; //先讓最早要乘的這格陣列值等於1
        for(int n = total;n>twos;n--){
            for(i=0;i<sx;i++)
            {
                x[i]=x[i]*n+v; //各個位數運算式，v是有進位時要加上去的
                v=x[i]/1000000000; //v若大於0，則需進位
                x[i]=x[i]%1000000000; //每格陣列存九位數
                if(v!=0&&i+1==sx){
                    //判斷陣列是否+1
                    sx++; //記錄陣列位數
                }     
            }
        }
        v=0; //清空v的值
        sy=1; //不管怎麼樣，s必會大於等於1，因為整數一定有位數
        y[0]=1; //先讓最早要乘的這格陣列值等於1
        for(int nk=total-twos;nk>0;nk--){
            for(i=0;i<sy;i++)
            {
                y[i]=y[i]*nk+v; //各個位數運算式，v是有進位時要加上去的
                v=y[i]/1000000000; //v若大於0，則需進位
                y[i]=y[i]%1000000000; //每格陣列存九位數
                if(v!=0&&i+1==sy){
                    //判斷陣列是否+1
                    sy++; //記錄陣列位數
                }     
            }
        }


        return nJ / (kJ * nkJ);
    }
    vector<int> bigMul(int n ,int m){
        vector<int> res(100,0);
        vector<int> m_SingleNo;\
        int m_b = 1;
        for(int i = 1;i<100 && m>0;i++){
            m_SingleNo.push_back(m% 10);
            m/=10;
        }
        int v = 0;//進位

    }
};
int main(){
    Solution sol;
    vector<int> res = sol.bigMul(100,543);
    int ans = sol.calculate(45,7);
    //int res = sol.calculate(3,1);
}
//1 <= n <= 45